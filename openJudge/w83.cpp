#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// 三维数组类拥有内部对象二维数组
// 所有数组都是从一维数组实现，用不同指针表示头位置
template <class T>
class CArray3D
{
public:
    T *pArray3;
    int nLayer, nRow, nCol;

public:
    class CArray2D
    {
    public:
        T *pArray2;
        int nCol;
        CArray2D(T *p_, int c_) : pArray2(p_), nCol(c_) {}

        T *operator[](int nRow)
        {
            return pArray2 + nRow * nCol;
        }

        // 类型转换函数 当CArray2D被 T* 作用时，返回pArray2
        // memset(CArray, s, n) 时， CArray被强制转换为 T*
        // ==> memset(pArray, s, n)
        operator T *()
        {
            return pArray2; //返回值本层的起始地址
        }
    };

    CArray3D(int layer_, int row_, int col_) : nLayer(layer_), nRow(row_), nCol(col_)
    {
        pArray3 = new T[nLayer * nRow * nCol];
    }

    CArray2D operator[](int i)
    {
        return CArray2D(pArray3 + i * nRow * nCol, nCol);
    }

    ~CArray3D()
    {
        delete[] pArray3;
    }
};

CArray3D<int> a(3, 4, 5);
CArray3D<double> b(3, 2, 2);
void PrintA()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << "layer " << i << ":" << endl;
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 5; ++k)
                cout << a[i][j][k] << ",";
            cout << endl;
        }
    }
}
void PrintB()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << "layer " << i << ":" << endl;
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
                cout << b[i][j][k] << ",";
            cout << endl;
        }
    }
}

int main()
{

    int No = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 5; ++k)
                a[i][j][k] = No++;
        }
    }
    PrintA();
    cout<<endl;
    memset(a[1], -1, 20 * sizeof(int));
    PrintA();
    cout<<endl;
    memset(a[1][1], 0, 5 * sizeof(int));
    PrintA();
    cout<<endl;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                b[i][j][k] = 10.0 / (i + j + k + 1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;

    return 0;
}

/* layer 0:
0,1,2,3,4,
5,6,7,8,9,
10,11,12,13,14,
15,16,17,18,19,
layer 1:
20,21,22,23,24,
25,26,27,28,29,
30,31,32,33,34,
35,36,37,38,39,
layer 2:
40,41,42,43,44,
45,46,47,48,49,
50,51,52,53,54,
55,56,57,58,59,
layer 0:
0,1,2,3,4,
5,6,7,8,9,
10,11,12,13,14,
15,16,17,18,19,
layer 1:
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
layer 2:
40,41,42,43,44,
45,46,47,48,49,
50,51,52,53,54,
55,56,57,58,59,
layer 0:
0,1,2,3,4,
5,6,7,8,9,
10,11,12,13,14,
15,16,17,18,19,
layer 1:
-1,-1,-1,-1,-1,
0,0,0,0,0,
-1,-1,-1,-1,-1,
-1,-1,-1,-1,-1,
layer 2:
40,41,42,43,44,
45,46,47,48,49,
50,51,52,53,54,
55,56,57,58,59,
layer 0:
10,5,
5,3.33333,
layer 1:
5,3.33333,
3.33333,2.5,
layer 2:
3.33333,2.5,
2.5,2,
****
7,3.33333 */