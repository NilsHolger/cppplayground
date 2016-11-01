#include "library.h"
#include "precompiled.h"
#include <wrl.h>

using namespace std;
using namespace Microsoft::WRL;


static ComPtr<ILion> CreateLion()
{
	ComPtr<ILion> lion;
	HR(CreateLion(lion.GetAddressOf()));
	return lion;
}

auto main() ->int
{
	ComPtr<ILion> lion = CreateLion();
	HR(CreateLion(lion.ReleaseAndGetAddressOf()));

	ComPtr<ILion> other = move(lion);
	lion = move(other);

	lion->Roar();

	ComPtr<ILion2> lion2;
	if (S_OK == lion.CopyTo(lion2.GetAddressOf()))
	{
		lion2->Hunt();
	}

	ComPtr<IOfflineLion> offline;
	if (S_OK == lion.CopyTo(offline.GetAddressOf()))
	{
		offline->Save("filename");
	}
}