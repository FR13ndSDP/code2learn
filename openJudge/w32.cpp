#include <iostream>
#include <string>
using namespace std;

class Base {
public:
	int k;
	Base(int n):k(n) { }
};
class Big
{
public:
	const int v;
	Base b;

    // 这里要使用列表初始化，为什么不在函数里初始化?
    Big(int n):b(n),v(n) { }

// 在此处补充你的代码
};
int main()
{
	int n;
	while(cin >>n) {
		Big a1(n);
		Big a2 = a1;
		cout << a1.v << "," << a1.b.k << endl;
		cout << a2.v << "," << a2.b.k << endl;
	}
}
