#pragma once
#include "headers.h"
#include "component.h"

class CompFactory
{
public:
	Component makeComp(int componentId)
	{
		Component comp;
		comp.componentId = componentId;
		return comp;
	}
};