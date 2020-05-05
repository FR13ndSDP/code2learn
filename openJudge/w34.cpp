#include <iostream>
using namespace std;

struct A
{
	int v;
	A(int vv) : v(vv) {}
	// 在此处补充你的代码
	// const A* 是返回值类型， 后面的const是规定常量成员函数
	const A *getPointer() const
	{
		return this;
	}
};

int main()
{
	const A a(10); // 常量对象上不能执行非常量函数
	const A *p = a.getPointer();
	cout << p->v << endl;
	return 0;
}