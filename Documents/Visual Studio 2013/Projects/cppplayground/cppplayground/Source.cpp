#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include "geometry.h"
using namespace std;

class Particle {
public:
	Particle(int id, string description) : m_id(id), m_description(move(description)) {}
	string description() const { return m_description; }
private:
	int m_id = 0;
	string m_description;
	int m_x_velocity = 0;
	int m_y_velocity = 0;
};

int main(){
	vector<Particle> particles;
	for (int i = 0; i < 10; ++i){
		particles.emplace_back(i, "ID: " + to_string(i));
	}
	for (const auto &p : particles){
		cout << "Particle: " << p.description() << "\n";
	}
}