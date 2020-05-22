#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ans;
        for (int i = 1; i <= n; ++i)
        {
            if (i % 15 == 0)
            {
                ans.emplace_back("FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                ans.emplace_back("Fizz");
            }
            else if (i % 5 == 0)
            {
                ans.emplace_back("Buzz");
            }
            else
            {
                ans.emplace_back(to_string(i));
            }
        }
        return ans;
    }
};

int main()
{
    int i;
    cin >> i;
    Solution s;
    vector<string> vec(i);
    vec = s.fizzBuzz(i);
    for (int j = 0; j < i; j++)
    {
        cout << vec.at(j) << endl;
    }
    cout << "end";
    return 0;
}
