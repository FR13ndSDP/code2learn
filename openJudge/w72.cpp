#include <iostream>
#include <string>
using namespace std;
// 在此处补充你的代码
template <class T, class pred>
void MyForeach(T *a, T *b, pred func)
{
    while (a!=b)
    {
        func(*a);
        a++;
    }
}

void Print(string s)
{
	cout << s;
}
void Inc(int & n)
{
	++ n;
}
string array[100];
int a[100];
int main() {
	int m,n;
	while(cin >> m >> n) {
		for(int i = 0;i < m; ++i)
			cin >> array[i];
		for(int j = 0; j < n; ++j)
			cin >> a[j];
		MyForeach(array,array+m,Print);		 
		cout << endl;
		MyForeach(a,a+n,Inc);		 
		for(int i = 0;i < n; ++i)
			cout << a[i] << ",";
		cout << endl;
	}
	return 0;
}
// IN:
// 3 4
// Tom Mike Jack
// 1 2 3 4
// 1 2
// Peking
// 100 200

// OUT:
// TomMikeJack
// 2,3,4,5,
// Peking
// 101,201,