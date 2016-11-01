#include "precompiled.h"
#include "handle.h"

using namespace OpenSourceOne;

typedef invalid_handle Transaction;

static Transaction CreateTransaction()
{
	return Transaction(CreateTransaction(nullptr,
		nullptr,
		TRANSACTION_DO_NOT_PROMOTE,
		0,
		0,
		INFINITE,
		nullptr));
}

struct RegistryKeyTraits
{
	typedef HKEY pointer;
	static pointer invalid() throw()
	{
		return nullptr;
	}
	static void close(pointer value) throw()
	{
		HANDLE_VERIFY_(ERROR_SUCCESS, RegCloseKey(value));
	}
};

typedef unique_handle<RegistryKeyTraits> RegistryKey;

static RegistryKey CreateRegistryKey(HKEY key,
									 wchar_t const * path,
									 Transaction const & transaction,
									 REGSAM access)
{
	HKEY handle = nullptr;
	auto result = RegCreateKeyTransacted(key,
		path,
		0,
		nullptr,
		REG_OPTION_NON_VOLATILE,
		access,
		nullptr,
		&handle,
		nullptr,
		transaction.get(),
		nullptr);

	if (ERROR_SUCCESS != result)
	{
		SetLastError(result);
	}
	return RegistryKey(handle);
}

static RegistryKey OpenRegistryKey(HKEY key,
	wchar_t const * path,
	Transaction const & transaction,
	REGSAM access)
{
	HKEY handle = nullptr;
	auto result = RegOpenKeyTransacted(key,
		path,
		0,
		access,
		&handle,
		transaction.get(),
		nullptr);

	if (ERROR_SUCCESS != result)
	{
		SetLastError(result);
	}
	return RegistryKey(handle);
}

enum class EntryOption
{
	None, Delete, FileName,
};

struct Entry
{
	wchar_t const * Path;
	EntryOption Option;

	wchar_t const * Name;
	wchar_t const * Value;
};

static Entry Table[] =
{
	{
		L"Software\\Classes\\CLSID\\{c155a74d-6b65-4301-80c8-d313c4443e05}",
		EntryOption::Delete,
		nullptr,
		L"Lion"
	},
	{
		L"Software\\Classes\\CLSID\\{c155a74d-6b65-4301-80c8-d313c4443e05}\\InprocServer32",
		EntryOption::FileName,
	},
	{
		L"Software\\Classes\\CLSID\\{c155a74d-6b65-4301-80c8-d313c4443e05}\\InprocServer32",
		EntryOption::None,
		L"ThreadingModel",
		L"Free",

	},
};

static bool Unregister(Transaction const & transaction)
{
	for (auto const & entry : Table)
	{
		if (EntryOption::Delete != entry.Option)
		{
			continue;
		}
		auto key = OpenRegistryKey(HKEY_LOCAL_MACHINE,
			entry.Path,
			transaction,
			DELETE | KEY_ENUMERATE_SUB_KEYS | KEY_QUERY_VALUE | KEY_SET_VALUE);
		if (!key)
		{
			if (ERROR_FILE_NOT_FOUND == GetLastError())
			{
				continue;
			}
			return false;
		}
		auto result = RegDeleteTree(key.get(), nullptr);
		if (ERROR_SUCCESS != result)
		{
			SetLastError(result);
			return false;
		}
	}
	return true;
}

static bool Register(Transaction  const & transaction)
{
	if (!Unregister(transaction))
	{
		return false;
	}

	wchar_t fileName[MAX_PATH];

	auto const length = GetModuleFileName(reinterpret_cast<HMODULE>(&__ImageBase),
		fileName,
		_countof(fileName));
	if (0 == length || _countof(fileName) == length)
	{
		return false;
	}										 

	for (auto const & entry : Table)
	{
		auto key = CreateRegistryKey(HKEY_LOCAL_MACHINE,
			entry.Path,
			transaction,
			KEY_WRITE);

		if (!key)
		{
			return false;
		}
		if (EntryOption::FileName != entry.Option &&
			!entry.Value)
		{
			continue;
		}

		auto value = entry.Value;
		if (!value)
		{
			ASSERT(EntryOption::FileName == entry.Option);
			value = fileName;
		}

		auto result = RegSetValueEx(key.get(), entry.Name, 0, REG_SZ, reinterpret_cast<BYTE const *>(value),
			static_cast<DWORD>(sizeof(wchar_t)* (wcslen(value) + 1)));
		if (ERROR_SUCCESS != result)
		{
			SetLastError(result);
			return false;
		}
	}
	return true;
}


HRESULT __stdcall DllRegisterServer()
{
	auto transaction = CreateTransaction();
	if (!transaction)
	{
		return HRESULT_FROM_WIN32(GetLastError());
	}
	if (!Register(transaction))
	{
		return HRESULT_FROM_WIN32(GetLastError());
	}

	if (!CommitTransaction(transaction.get()))
	{
		return HRESULT_FROM_WIN32(GetLastError());
	}

	return S_OK;
}

HRESULT __stdcall DllUnregisterServer()
{
	auto transaction = CreateTransaction();
	if (!transaction)
	{
		return HRESULT_FROM_WIN32(GetLastError());
	}
	
	if (!Unregister(transaction))
	{
		return HRESULT_FROM_WIN32(GetLastError());
	}

	if (!CommitTransaction(transaction.get()))
	{
		return HRESULT_FROM_WIN32(GetLastError());
	}
	return S_OK;
}


