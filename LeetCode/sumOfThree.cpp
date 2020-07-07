#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n<3)
            return ans;
        int sum=0;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums[n-1] <0) // 一定不存在
            return {};

        for (int i=0; i< n-2 && nums[i] <= 0; i++)
        {
            if (i>0 && nums[i] == nums[i-1])
                continue;
            int header = i+1;
            int tailer = n-1;
            while (tailer > header && nums[tailer] >= 0){
                sum = nums[i] + nums[header] + nums[tailer];
                if (sum == 0){
                    ans.push_back({nums[i], nums[header], nums[tailer]});
                    while (tailer > header && nums[header] == nums[header+1])
                        header ++;
                    while (tailer > header && nums[tailer] == nums[tailer-1])
                        tailer --;
                    header ++;
                    tailer --;
                }
                else if (sum < 0)
                    header ++;
                else
                    tailer --;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums({0,0,0});
    Solution S;
    vector<vector<int>> Vec = S.threeSum(nums);
    for (int i=0; i<Vec.size(); i++)
        for (int j=0; j<3; j++){
            {
                cout << Vec[i][j];
            }
        }
    return 0;
}
