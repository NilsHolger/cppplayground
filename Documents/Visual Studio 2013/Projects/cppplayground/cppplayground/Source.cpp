#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iterator>
#include <cstring>
using namespace std;

struct Vowel_Count {
	Vowel_Count(string t_word, const int t_num_vowels)
		:word(move(t_word)),num_vowels(t_num_vowels)  {}

	int get_count() const {
		++cache_calls;
		return num_vowels;
	}
	string word;
private:
	int num_vowels;
	mutable int cache_calls = 0;
};
bool is_vowel(const char c){
	vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
	return any_of(begin(vowels), end(vowels), [&](const char v) { return c == v; });
}
int count_vowels(string t_str){
	
	return count_if(begin(t_str), end(t_str), &is_vowel);
}

int main(){
	vector<string> s1 = { "she", "has", "a", "sexy", "string" };
	vector<Vowel_Count> vowel_counts;
	for (auto itr : s1){
		transform(begin(itr), end(itr), begin(itr), [](const char c){return tolower(c); });
		const auto vowel_count = count_vowels(itr);
		vowel_counts.emplace_back(move(itr), vowel_count);
	}
	for (const auto &vc : vowel_counts){
		cout << vc.word << ": " << vc.get_count() << '\n';
	}
}