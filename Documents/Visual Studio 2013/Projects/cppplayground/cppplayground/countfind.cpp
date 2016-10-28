#include "headers.h"
using namespace std;


enum Color { Red, Green, Blue, Rainbow};
enum class GameState : short { Win = 1, Loose, Live, Die};

union Data
{
	int integer;
	float fNumber;
	char* text;
};

struct Size
{
	int width, height;
};

auto main() -> int 
{
	Size s{ 11, 10 };
	cout << s.height << '\n';
	getchar();
}



