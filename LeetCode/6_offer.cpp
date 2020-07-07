#include <iostream>
#include <vector>
#include <stack>
using namespace std;

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        vector<int> res;
        while (head != NULL)
        {
            stk.push(head->val);
            head = head->next;
        }
        for (int i=0; i< stk.size(); i++)
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    vec = s.reversePrint(head);
    for (auto i:vec)
        cout << i << " ";
    cout << endl;
    return 0;
}