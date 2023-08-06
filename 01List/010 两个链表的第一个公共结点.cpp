#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//使得两链表长度一致
class Solution {
  public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        auto p1 = pHead1, p2 = pHead2;
        while (p1 != p2) {
            p1 = p1 ? p1->next : pHead2;
            p2 = p2 ? p2->next : pHead1;
        }
        return p1;
    }
};
