#pragma once


#include <unknwn.h>

struct __declspec(uuid("c155a74d-6b65-4301-80c8-d313c4443e05")) Lion;


struct __declspec(uuid("dccf2541-f2b6-4780-98eb-3b4653e03704")) ILion : IUnknown
{
	virtual void __stdcall Roar() = 0;
};
