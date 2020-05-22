#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> b;
        int i=0;
        while (i< m+n-1)
        {
            if (i%2 == 0)
            {
                int x = (i<m)? i:m-1;
                int y = i-x;
                while (x>=0 && y<n)
                {
                    b.push_back(matrix[x][y]);
                    x--;
                    y++;
                }
            }
            else
            {
                int y1 = (i<n)? i:n-1;
                int x1 = i-y1;
                while (x1<m && y1>=0)
                {
                    b.push_back(matrix[x1][y1]);
                    x1++;
                    y1--;
                }
            }
            i++;
        }
        return b;
    }
};

int main()
{
    vector<vector<int> > A(4, vector<int>(3));
    vector<int> b;
    int a[]={0,1,2,3,4,5,6,7,8,9,10,11};
    int *ptr = a;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<3;j++)
        {
            A[i][j] = *ptr;
            ptr++;
        }
    }

    Solution s;
    b = s.findDiagonalOrder(A);
    for (int i=0;i<b.size();i++)
    {
        cout << b[i]<<endl;
    }
    return 0;
}