#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int> > dp(m+1,vector<int>(n+1, INT32_MAX));
        dp[m-1][n] = dp[m][n-1] = 1;
        for (int i=m-1;i>=0; --i) {
            for(int j=n-1; j>=0; --j) {
                dp[i][j] = max( min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1);
            }
        }
        for (int i=0;i<m;++i){
            for (int j=0; j<n; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][0];
    }
};

int main() {
    vector<vector<int> > dungeon = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    Solution s;
    int health = s.calculateMinimumHP(dungeon);
    cout << "min health:" << health << endl;
    return 0;
}
