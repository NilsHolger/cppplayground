#include "headers.h"
using namespace std;
struct Base
{
	Base() { cout << " Base::Base()\n"; }
	~Base() { cout << " ~Base::Base()\n"; }
};
struct Derived : public Base
{
	Derived() { cout << " Derived::Derived()\n"; }
	~Derived() { cout << " Derived::~Derived()\n"; }
};
void thr(shared_ptr<Base> p)
{
	this_thread::sleep_for(chrono::seconds(1));
	shared_ptr<Base> lp = p; //thread safe
	{
		static mutex io_mutex;
		lock_guard<mutex> lk(io_mutex);
		cout << "local pointer in a thread:\n"
			<< " lp.get() = " << lp.get()
			<< ", lp.use_count() =" << lp.use_count() << '\n';
	}
}
auto main() -> int
{
	shared_ptr<Base> p = make_shared<Derived>();
	cout << p.get() << '\n' << p.use_count() << '\n';
	thread t1(thr, p), t2(thr, p), t3(thr, p);
	p.reset();
	cout << p.get() << '\n' << p.use_count() << '\n';
	t1.join(); t2.join(); t3.join();
	cout << "all threads completed";
	getchar();
}

