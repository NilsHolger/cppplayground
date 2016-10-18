#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Shape {
	virtual void setX(int xcor) = 0;
	virtual void setY(int ycor) = 0;
	virtual int getX() const = 0;
	virtual int getY() const = 0;
	virtual void draw() const = 0;
};

class Circle : public Shape {
private:
	int x, y, rad;
public:
	Circle(int xcor, int ycor, int r){
		x = xcor;
		y = ycor;
		rad = r;
	}
	~Circle() {}
	virtual void setX(int xcor) {}
	virtual void setY(int ycor) {}
	void setRadius(int r){ rad = r; }
	virtual int getX() const { return x; }
	virtual int getY() const { return y; }
	int getRadius()	const { return rad; }
	virtual void draw()	const {
		cout << "drawing circle at: " << getX() << ", " << getY() << " with a radius of: " << getRadius() << "\n";
	}
};

int main(){
	Circle c1(1, 2, 3);
	c1.draw();
}