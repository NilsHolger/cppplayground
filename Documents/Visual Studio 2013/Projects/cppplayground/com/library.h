#pragma once


struct ILion
{
	virtual void __stdcall Roar() = 0;
	virtual void __stdcall Attack() = 0;
};

ILion* __stdcall CreateLion();