#include <iostream>
using namespace std;

class A
{
    public:
        virtual void foo()
        {
            cout << "A::foo" << endl;
        }
};

class B:public A
{
    public:
        virtual void foo()
        {
            cout << "B::foo" << endl;
        }
};

int main()
{
    A a;
    A *pa = new B();
    pa->foo();
    long long *p1 = (long long *) &a;
    long long *p2 = (long long *) pa;
    // 覆盖虚函数表
    *p2 = *p1;
    pa->foo();
    return 0;
}