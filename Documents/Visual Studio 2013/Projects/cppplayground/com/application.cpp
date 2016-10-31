#include "library.h"



//auto main() -> int
//{
//	ILion *lion = CreateLion();
//	lion->Roar();
//	//lion->Attack();
//	
//	ILion2 * lion2 = static_cast<ILion2 *>(lion->As("ILion2"));
//
//	if (lion2)
//	{
//		lion2->Hunt();
//		lion2->Release();
//	}
//
//	IOfflineLion * offline = static_cast<IOfflineLion *>(lion->As("IOfflineLion"));
//
//	if (offline)
//	{
//		offline->Save("filename");
//		offline->Release();
//	}
//
//
//	lion->Release();
//}