#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size()+nums2.size();
        vector<int> summary;
        for (int i= 0; i<nums1.size(); i++)
        {
            summary.push_back(nums1[i]);
        }
        for (int i= 0; i<nums2.size(); i++)
        {
            summary.push_back(nums2[i]);
        }
        sort(summary.begin(), summary.end());
        if (len%2)
            return summary[len/2];
        else
            return (summary[len/2]+summary[len/2+1])/2.0;
    }
};

int main()
{
    vector<int> num1({1,1,2}), num2({2,3});
    Solution S;
    double ans = S.findMedianSortedArrays(num1,num2);
    cout << ans << endl;
    return 0;
}
