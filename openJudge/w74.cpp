#include <iostream>
using namespace std;
class MyCin
{
// 在此处补充你的代码
private:
    bool valid;
public:
    MyCin():valid(true) {}

    MyCin &operator>>(int &n)
    {
        cin >> n;
        if (n == -1)
            valid = false;
        return *this;
    }

    // KEY
    // 在需要bool变量的时候，隐式返回 valid
    operator bool()
    {
        return valid;
    }
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) // 发生了向bool的隐式转换,valid被返回
        cout  << n1 << " " << n2 << endl;
    return 0;
}