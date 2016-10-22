#include "headers.h"
using namespace std;

template<typename T, size_t Size>
class Values {

	static_assert(Size > 1, "use a scalar");
	T values[Size];
};
template<typename T, typename U>
auto multiply(T t, U u) -> int { 
	static_assert(is_integral<T>::value, "first val must be an int");
	return t * u;
}
int main(){
	Values<string, 2> v; 
	cout << multiply(10,10) << '\n';
}