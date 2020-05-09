#include <iostream>
#include <cstring>
using namespace std;

class Array2
{
    // 补充代码
    int x, y;
    int *ptr;

public:
    Array2() { ptr = NULL; }
    Array2(int x_, int y_) : x(x_), y(y_)
    {
        ptr = new int[x * y];
    }
    Array2(Array2 &a) : x(a.x), y(a.y)
    {
        ptr = new int[x * y];
        memcpy(ptr, a.ptr, sizeof(int) * x * y);
    }
    Array2 &operator=(const Array2 &a)
    {
        if (ptr)
            delete[] ptr;
        x = a.x;
        y = a.y;
        ptr = new int[x * y];
        memcpy(ptr, a.ptr, sizeof(int) * x * y);
        return *this;
    }
    ~Array2()
    {
        if (ptr)
            delete[] ptr;
    }
    // be careful here
    int *operator[](int i)
    {
        return ptr + i * y;
    }
    int &operator()(int i, int j)
    {
        return ptr[i * y + j];
    }
};

int main()
{
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}