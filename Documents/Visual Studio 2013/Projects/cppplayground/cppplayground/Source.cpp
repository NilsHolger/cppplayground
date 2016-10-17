#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>
#include <chrono>
#include "geometry.h"
#include "windows.h"
#include <cmath>
#include <memory>
#include <array>
#include <map>
#include <list>
using namespace std;

enum class Types {
	Double,
	Int
};

struct Value_Holder {
	Value_Holder(int t_i) : m_int(t_i), m_type(Types::Int){}
	Value_Holder(double t_d) : m_double(t_d), m_type(Types::Double){}

	Types type() const {
		return m_type;
	}
	double as_double() const {
		if (m_type == Types::Double){
			return m_double;
		}
		else {
			return m_int;
		}
	}
	int as_int() const {
		if (m_type == Types::Int){
			return m_int;
		}
		else {
			return m_double;
		}
	}
	void print() const {
		if (m_type == Types::Int){
			cout << m_int << "\n";
		}
		else {
			cout << m_double << "\n";
		}
	}
	int m_int = 0;
	double m_double = 0;
	Types m_type;															  
};

struct Operation {
	virtual ~Operation() = default;
	Operation(const Operation &) = default;
	//Operation(Operation &&) = default;
	Operation&operator = (const Operation &) = default;
	//Operation&operator = (Operation &&) = default;

	Operation(vector<Types> t_types) : m_types(t_types){}
	virtual Value_Holder do_call(vector<Value_Holder> & t_values) = 0;
	const vector<Types> &get_types() {
		return m_types;
	}
private:
	vector<Types> m_types;
};

struct Operation_Double_Sum : Operation {
	Operation_Double_Sum() : Operation({ Types::Double, Types::Double })
	{
	}
	Value_Holder do_call(const vector<Value_Holder> &t_values){
		cout << "double sum called\n";
		return t_values[0].as_double() + t_values[1].as_double();
	}
};
struct Operation_Int_Sum : Operation {
	Operation_Int_Sum() : Operation({ Types::Int, Types::Int}){}
	Value_Holder do_call(const vector<Value_Holder> & t_values){
		cout << "int sum called\n";
		return t_values[0].as_int() + t_values[1].as_int();
	}
};
struct Operation_Int_3_Sum : Operation {
	Operation_Int_3_Sum() : Operation({ Types::Int, Types::Int, Types::Int }){}
	Value_Holder do_call(const vector<Value_Holder> & t_values){
		cout << "int sum 3 called\n";
		return t_values[0].as_int() + t_values[1].as_int() + t_values[2].as_int();
	}
};

struct Op_Caller {
	vector<unique_ptr<Operation>> operations;
	void add_operation(unique_ptr<Operation> t_op){
		operations.emplace_back(move(t_op));
	}
	Value_Holder do_call(const vector<Value_Holder> &t_values){
		for (size_t i = 0; i < t_values.size(); i++){
			for (const auto &oper : operations){
				if (t_values.size() == oper->get_types().size()){
					const auto num_diffs = inner_product(begin(oper->get_types()), end(oper->get_types()),
						begin(t_values), 0, 
						plus<>(),
						[](const Types & type, const Value_Holder &value){
						return type == value.type() ? 0 : 1;
					}
					);
					if (i == num_diffs){
						return oper->do_call(t_values);
					}
				}
			}
		}
		throw std::runtime_error("No matching function call");
	}
};

int main(){
	Op_Caller oc;
	oc.add_operation(make_unique<Operation_Double_Sum>());
	oc.add_operation(make_unique<Operation_Int_Sum>());
	oc.add_operation(make_unique<Operation_Int_3_Sum>());

	for (int i = 0; i < 10000; i++){
		cout << oc.do_call({ 3, 4, 5 }).as_int() << "\n";	  //12
		cout << oc.do_call({ 3.4, 5 }).as_double() << "\n";	  //8.4
		cout << oc.do_call({ 3, 4 }).as_int() << "\n";		  //7
		cout << oc.do_call({ 3, 4.9 }).as_double() << "\n";	  //7.9
		cout << oc.do_call({ 3.4, 4.9 }).as_double() << "\n"; //8.3
	}

}							 