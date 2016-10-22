#include "headers.h"
using namespace std;

auto sum() -> double { return 0.0; }
template<typename H, typename ... T>
auto sum(H h, T... t) -> double //-> decltype(h+sum(t...))
{
	return h + sum(t ...);
}

int main(){
	cout << sum(99.1, 0.98) << '\n';
}