#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for (auto i:s)
        {
            if (i == ' ') ans+="%20";
            else
                ans+=i;
        }
        return ans;
    }
};

int main()
{
    string s = "hello thr er";
    Solution S;
    string s2 = S.replaceSpace(s);
    cout << s2 <<endl;
    return 0;
}