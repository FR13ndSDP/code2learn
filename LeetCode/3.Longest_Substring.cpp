#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int n = s.size();
        int rk = -1, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                set.erase(s[i-1]);
            // 当set内没有rk后的元素，插入这个元素
            while (rk+1 < n && !set.count(s[rk+1]))
            {
                set.insert(s[rk+1]);
                ++rk;
            }
            ans = max(ans, rk-i+1);
        }
        return ans;
    }
    // 数组代替哈希表
    int leng2(string s) {
        int set[130] = {0};
        int n = s.size();
        int rk = -1, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                set[s[i-1]] = 0;
            // 当set内没有rk后的元素，插入这个元素
            while (rk+1 < n && set[s[rk+1]] == 0)
            {
                set[s[++rk]] = 1;
            }
            ans = max(ans, rk-i+1);
        }
        return ans;
    }
};

int main()
{
    std::string s = "sbdfjdjss";
    Solution sol;
    int len = sol.leng2(s);
    std::cout << len << std::endl;
    return 0;
}