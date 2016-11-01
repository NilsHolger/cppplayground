#include "library.h"
#include "precompiled.h"

template<typename T>
class RemoveAddRefRelease : public T
{
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
};

template <typename T>
class ComPtr
{
	T * m_ptr;
public:
	ComPtr() : m_ptr(0){}
	~ComPtr()
	{
		if (m_ptr)
		{
			m_ptr->Release();
		}
	}
	RemoveAddRefRelease<T> * operator->() const
	{
		ASSERT(m_ptr);
		return static_cast<RemoveAddRefRelease<T> *>(m_ptr);
	}
	T ** GetAddressOf()
	{
		ASSERT(!m_ptr);
		return &m_ptr;
	}
};

auto main() -> int
{
	ComPtr<ILion> lion;

	if (S_OK != CreateLion(lion.GetAddressOf()))
	{
		return 0;
	}
	lion->Roar();
	//lion->Attack();
	
	ComPtr<ILion2> lion2;

	if (S_OK == lion->QueryInterface(lion2.GetAddressOf()))
	{
		lion2->Hunt();
	}

	ComPtr<IOfflineLion> offline;

	if (S_OK == lion->QueryInterface(offline.GetAddressOf()))
	{
		offline->Save("filename");
	}
}