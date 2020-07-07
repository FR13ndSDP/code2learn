#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ( matrix[i][j] == 1)
                {
                    if (i ==0 || j== 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

int main()
{
    int a[3][4] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1};
    vector<vector<int>> matrix(3, vector<int>(4));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = a[i][j];
        }
    }
    Solution s;
    int ans = s.countSquares(matrix);
    cout << ans << endl;
    return 0;
}