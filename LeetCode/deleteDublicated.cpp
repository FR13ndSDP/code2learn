#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0) return 0; //又是这种坑爹情况
        int i = 0, j = 0; //i慢 j快
        while (j < len)
        {
            if (nums[i] != nums[j])
                nums[++i] = nums[j];
            j++;
        }
        return i + 1;
    }
};


int main()
{
    Solution sol;
    int array[5] = {0, 1, 1, 2, 2};
    vector<int> nums(array, array + 5);
    int n = sol.removeDuplicates(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    cout << n;
    return 0;
}