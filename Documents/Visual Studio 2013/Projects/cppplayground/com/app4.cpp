#include "library.h"
#include "precompiled.h"
//#include <atlbase.h>

using namespace std;


static CComPtr<ILion> CreateLion()
{
	CComPtr<ILion> lion;
	HR(CreateLion(&lion));
	return lion;
}


//auto main() -> int
//{
//		CComPtr<ILion> lion = CreateLion();
//
//		lion->Roar();
//
//		CComPtr<ILion2> lion2;
//
//		if (S_OK == lion->QueryInterface(&lion2))
//		{
//			lion2->Hunt();
//		}
//	
//		CComPtr<IOfflineLion> offline;
//
//		if (S_OK == lion->QueryInterface(&offline))
//		{
//			offline->Save("filename");
//		}
//	
//}







