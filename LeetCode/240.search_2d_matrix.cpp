#include <iostream>
#include <vector>
using namespace std;

// 最关键的是寻找起点，起点的两个方向需要分别是递增和递减
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // if (matrix[0].size() == 0)
        //     return false;
        int i = matrix.size()-1;
        int j = 0;
        int n = matrix[0].size()-1;
        while (i>=0 && j < matrix[0].size())
        {
            if (target == matrix[i][j]) return true;
            else if (target > matrix[i][j]) j++;
            else i--;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix({{}});
    cout << matrix.size() << matrix[0].size() << endl;
    Solution s;
    cout << s.findNumberIn2DArray(matrix, 1);
    return 0;
}