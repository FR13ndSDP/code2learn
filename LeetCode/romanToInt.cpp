#include <iostream>
#include <map>
using namespace std;

class Solution{
public:

//最直接的方法
    int romanToInt(string s){
        int num = 0;
        for (int i=0; i< s.size(); i++)
        {
            switch (s[i])
            {
            case 'I':
                if (s[i+1] == 'V' || s[i+1] == 'X')
                    num -= 1;
                else
                    num += 1;
                break;
            case 'V':
                num += 5;
                break;
            case 'X':
                if (s[i+1] == 'L' || s[i+1] == 'C')
                    num -= 10;
                else
                    num += 10;
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                if (s[i+1] == 'D' || s[i+1] == 'M')
                    num -= 100;
                else
                    num += 100;
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;  
            default:
                break;
            }
        }
        return num;
    }

// 哈希表
    int romanToInt2(string s)
    {
        int num = 0;
        map<char, int> hashTable = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        for (int i =0; i< s.size(); i++)
        {
            if (hashTable[s[i]] < hashTable[s[i+1]])
                num -= hashTable[s[i]];
            else
                num+= hashTable[s[i]];
        }
        return num;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    int num = sol.romanToInt2(s);
    cout<< num << endl;
    return 0; 
}