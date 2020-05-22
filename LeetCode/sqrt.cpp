#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:

// 二分法
    int mySqrt(int x) {
        if (x == 0 | x == 1)
            return x;
        int l = 0;
        int r = x;
        while (l < r)
        {
            int mid = l+ (r-l)/2; // 不写成平常的平均式，防止溢出
            if (x/mid == mid)
            {
                return mid;
            }
            else if (x/mid > mid) // mid * mid会溢出
            {
                l = mid +1;
            }
            else
            {
                r = mid;
            }
        }
        
        return l-1;
    }
// 牛顿迭代法
    int nSqrt(int x)
    {
        if(x == 0) // 防止除0
            return 0;
        double c = x, x0 = x;  // y= x^2 - c, 初值x0 = c
        while(true)
        {
            double xi = 0.5*(x0+c/x0);
            if (fabs(x0 - xi) < 1e-7)
            {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};

int main()
{
    Solution s;
    for (int i = 0; i < 10; i++)
    {
        cout << i << "\t"<< s.nSqrt(i)<< endl;
    }
    
    cout << s.nSqrt(2147395600) <<endl;
    return 0;
}