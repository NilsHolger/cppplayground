#pragma once

struct IObject
{
	virtual void __stdcall AddRef() = 0;
	virtual void __stdcall Release() = 0;
	virtual void* __stdcall As(char const * type) = 0;
};

struct ILion : IObject
{
	virtual void __stdcall Roar() = 0;
	virtual void __stdcall Attack() = 0;
};

struct ILion2 : ILion
{
	virtual void __stdcall Hunt() = 0;
};

struct IOfflineLion : IObject
{
	virtual void __stdcall Load(char const *file) = 0;
	virtual void __stdcall Save(char const *file) = 0;
};


ILion* __stdcall CreateLion();