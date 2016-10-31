#pragma once

#include <unknwn.h>

struct _declspec(uuid("d2f20126-eb9a-4f5c-bc33-1f24dbc266a6")) ILion : IUnknown
{
	virtual void __stdcall Roar() = 0;
	virtual void __stdcall Attack() = 0;
};

struct _declspec(uuid("699833cc-dcd6-4bea-a719-96423678ea51")) ILion2 : ILion
{
	virtual void __stdcall Hunt() = 0;
};

struct _declspec(uuid("ba372aa8-2fc3-407c-aa35-f3ae77e96b00")) IOfflineLion : IUnknown
{
	virtual void __stdcall Load(char const *file) = 0;
	virtual void __stdcall Save(char const *file) = 0;
};

HRESULT __stdcall CreateLion(ILion ** lion);