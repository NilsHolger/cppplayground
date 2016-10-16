#include "geometry.h"
#include <cmath>


double calculate_area_circle(double radius){
	const double PI = 3.141592;
	return PI * pow(radius, 2);
}
