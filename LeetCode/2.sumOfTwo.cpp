#include <iostream>

// 单链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *ans;
        ans->val = 
    }
};

int main()
{
    Solution S;
    ListNode *L = new ListNode(0);
    ListNode *L2 = new ListNode(1);
    L->next = L2;
    std::cout << L->next->val;
    return 0;
}

