#include "precompiled.h"
#include "assert.h"

#pragma comment(lib, "rpcrt4.lib")

using namespace std;

//auto main() -> int
//{
//	GUID guid = //cad3eaba-6814-47e7-9c55-f8988b612c65
//	{
//		0xcad3eaba,
//		0x6814,
//		0x47e7,
//		{ 0x9c, 0x55, 0xf8, 0x98, 0x8b, 0x61, 0x2c, 0x65 }
//	};
//	struct __declspec(uuid("cad3eaba-6814-47e7-9c55-f8988b612c65")) TypeName;
//
//	GUID guid2 = __uuidof(TypeName);
//
//	//GUID guid;
//	//HR(CoCreateGuid(&guid));
//
//	//unsigned short * rpc_string;
//	//ASSERT(RPC_S_OK == UuidToString(&guid, &rpc_string));
//
//	//TRACE(L"%s\n", rpc_string);
//
//	//wchar_t ole_string[39];
//	//ASSERT(StringFromGUID2(guid, ole_string, _countof(ole_string)));
//
//	//TRACE(L"%s\n", ole_string);
//
//	//wstring std_string(ole_string + 1, _countof(ole_string) - 3);
//	//
//	//TRACE(L"%s\n", std_string.c_str());
//
//	//GUID guid2;
//	//ASSERT(RPC_S_OK == UuidFromString(rpc_string, &guid2));
//
//	//HR(CLSIDFromString(ole_string, &guid2));
//
//	//ASSERT(RPC_S_OK == 
//	//	UuidFromString(reinterpret_cast<unsigned short*>(const_cast<wchar_t*>(std_string.c_str())), &guid2));
//
//	//
//	//ASSERT(RPC_S_OK == RpcStringFree(&rpc_string));
//}