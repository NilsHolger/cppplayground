#include "precompiled.h"
#include "..\server\server.h"

using namespace std;
using namespace Microsoft::WRL;


auto main() -> int
{
	ComRuntime runtime;

	ComPtr<ICave> cave;

	HR(CoGetClassObject(__uuidof(Lion), CLSCTX_INPROC_SERVER,
		nullptr, __uuidof(cave), reinterpret_cast<void **>(cave.GetAddressOf())));
	ComPtr<ILion> lion;
	HR(cave->CreateLion(lion.GetAddressOf()));
	lion->Roar();
}