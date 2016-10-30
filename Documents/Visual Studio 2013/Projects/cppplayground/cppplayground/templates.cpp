#include "headers.h"
using namespace std;

typedef pair<int, int> int_pair;
//typedef tuple<int, int, int> int_tuple;


//int_tuple sum_prod_avg(int a, int b, int c)
//{
//	int_tuple t{ a + b + c, a * b * c, (a + b + c) / 3 };
//	return t;
//}

template<typename T1, typename T2, typename T3>
struct triple
{
	typedef T1 result_type;
	T1 first; T2 second; T3 third;
	triple(const T1& first, const T2& second, const T3& third) : 
		first(first), second(second), third(third){}
};

typedef triple<int, int, int> trie;
//trie sum_prod_avg(int a, int b, int c)
//{
//	return trie(a + b + c, a*b*c, (a + b + c) / 3);
//}
template<typename T1, typename T2, typename T3>
triple<T1, T2, T3> sum_prod_avg(const T1& a,
	const T2& b, const T3& c)
{
	return triple<T1, T2, T3>(a+b+c, a*b*c, (a+b+c) / triple<T1,T2,T3>::result_type(3));
}																		  

int_pair sum_and_product(int a, int b)
{
	return int_pair(a + b, a * b);
}
void consume_template()
{
	//int a = 8, b = 16, c = 32;
	//auto result = sum_and_product(a, b);
	//auto result1 = sum_prod_avg(a, b, c);
	//cout << "sum: " << result.first << " product: " << result.second << '\n';
	//cout << "sum: " << get<0>(result) << " product: " << get<1>(result) << '\n';
	//cout << "sum: " << result1.first << " product: " << result1.second
	//	<< " average: " << result1.third << '\n';
}
void consume_template_function()
{
	int a = 2; double b = 5.0; float c = -3.5;
	auto result = sum_prod_avg(a, b, c);
	cout << "sum: " << result.first << " product: " << result.second
		<< " average: " << result.third << '\n';
}
typedef complex<double> cd;
typedef triple<cd, cd, cd> cdt;

template<> cdt sum_prod_avg(const cd& a, const cd& b, const cd& c)
{
	auto result = sum_prod_avg(a.real(), b.real(), c.real());
	return cdt(result.first, result.second, result.third);
}

void consume_template_specialization()
{
	cd a(2, 3), b(3, 4), c(4, 5);
	auto result = sum_prod_avg(a, b, c);
	cout << result.first << ", " << result.second << ", " << result.third;

}

auto main() -> int
{
	//consume_template();
	//consume_template_function();
	//consume_template_specialization();
	getchar();
}