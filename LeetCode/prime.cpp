#include <iostream>
#include <vector>
#include <cstring>
#include <ctime>
using namespace std;
clock_t start, endtime;

class Solution {
public:
// 暴力解法
    int countPrimes(int n) {
        // 从3开始
        if (n<3)
        {
            return 0;
        }
        int count=1;
        for (int i=3; i<n; i++)
        {
            if ((i&1) == 0)
                continue;
            bool flag = true;
            for (int j = 3; j*j<=i; j+=2)
            {
                if (i%j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                count ++;
        }
        return count;
    }
// 筛法求素数
    int countPrimes2(int n) {
        if (n == 0)
            return 0;
        int count = 0;
        bool sign[n];
        memset(sign, true, sizeof(sign));
        for (int i = 2; i*i< n ; i++) {
            if (sign[i]) {
                for (int j = i*i; j < n; j+=i)
                    sign[j] = false;
            }
        }
        for (int i = 2; i < n; i++){
            if (sign[i])
                count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    start = clock();
    cout<<s.countPrimes2(1500000)<< endl;
    endtime = clock();
    double timeStep=(double)(endtime-start)/CLOCKS_PER_SEC;
    cout<<"Total time:"<<timeStep*1000 <<"ms"<<endl;
    return 0;
}