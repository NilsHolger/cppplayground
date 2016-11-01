//#include "library.h"
#include "precompiled.h"
#define TRACE OutputDebugString

using namespace std;

struct Lion
{
	Lion() { TRACE(L"Roar!\n"); }

	~Lion()	{ TRACE(L"Lions never die, they multiply.\n"); }

	//
	//ILion
	//

	void Roar()
	{
		TRACE(L"Roar\n");
	}

	void Attack()
	{
		TRACE(L"Attack\n");
	}

	//
	//ILion2
	//
	void Hunt()
	{
		TRACE(L"Hunt!\n");
	}
	//
	//IOfflineLion
	//
	void Load(char const * /*file*/)
	{

	}
	void Save(char const * /*file*/)
	{

	}
};

//auto main() -> int
//{
//	//unique_ptr<Lion> lion = make_unique<Lion>();
//	//unique_ptr<Lion> lion(new Lion);
//	shared_ptr<Lion> lion = make_shared<Lion>();
//	//shared_ptr<Lion> lion(new Lion);
//	lion->Roar();
//	
//	//unique_ptr<Lion> other = move(lion);
//	shared_ptr<Lion> other = lion;
//
//	lion->Hunt();
//}