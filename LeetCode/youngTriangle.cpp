#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > Triangle;
        vector<int> vec={1};
        while (numRows-->0)
        {
            Triangle.push_back(vec);
            for (int i = vec.size() - 1; i >= 1; i--)
                vec[i] +=  vec[i - 1];
            vec.push_back(1);
        }
        return Triangle;
    }
};

int main()
{
    vector<vector<int> > ans;
    Solution A;
    ans = A.generate(8);
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<ans[i].size();j++)
        {
            cout << ans[i][j]<< ",";
        }
        cout <<endl;
    }
    return 0;
}