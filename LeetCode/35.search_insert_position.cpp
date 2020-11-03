#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r = n-1;
        int ans = n;
        while (r >= l) {
            int mid = (l+r)/2;
            if (nums[mid] < target) l = mid+1;
            else if (nums[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } 
        }
        return ans;
    }
};

int main(int argc, char **argv) {
    vector<int> nums{1,3,5,6};
    for (int i=0; i<4; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    int target;
    cin >> target;
    Solution s;
    int ans = s.searchInsert(nums, target);
    cout << ans << endl;
    return 0;
}
