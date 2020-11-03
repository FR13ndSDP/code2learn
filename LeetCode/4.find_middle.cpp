#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


// O(log(m+n))
class Solution {
public:
    double getKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int id1 = 0, id2 = 0;
        while (true) {
            
            if (id1 == m) {
                return nums2[id2 + k - 1];
            }
            if (id2 == n) {
                return nums1[id1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[id1], nums2[id2]);
            }
            int newId1 = min(id1 + k / 2 - 1, m - 1);
            int newId2 = min(id2 + k / 2 - 1, n - 1);
            if (nums1[newId1] <= nums2[newId2]) {
                k -= (newId1 - id1 + 1);
                id1 = newId1 + 1;
            } else {
                k -= (newId2 - id2 + 1);
                id2 = newId2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKth(nums1, nums2, (totalLength + 1) / 2);
        } else {
            return (getKth(nums1, nums2, totalLength / 2) +
                    getKth(nums1, nums2, totalLength / 2 + 1)) /
                   2.0;
        }
    }
};

int main() {
    vector<int> num1({1, 2}), num2({3, 4});
    Solution S;
    double ans = S.findMedianSortedArrays(num1, num2);
    cout << ans << endl;
    return 0;
}