#include <iostream>
using namespace std;
void fun()
{
	cout << "from fun" << endl;
}
class Base
{
public :
	void bfun(){ cout << "from b fun" << endl; }
	static void sbfun(){ cout << "from sb fun" << endl; }

};
typedef void(*FUNCP)();
int main()
{
	FUNCP fp = fun;
	FUNCP fp2 = &fun;
	fp();
	fp2();
	void (*ppp)();
	ppp = &fun;
	(*ppp)();
	void (Base::*bfunpp)();
	bfunpp = &Base::bfun;
	Base tmp;
	(tmp.*bfunpp)();
	void (*sbfunpp)();
	sbfunpp = &Base::sbfun;
	(*sbfunpp)();

	//bfunpp();
	return 0;
}