#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    ListNode* hasCycle(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        auto slow = head;
        auto fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                return slow;
        }
        return nullptr;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        auto slow = hasCycle(pHead);
        if (slow==nullptr)
            return nullptr;
        
        auto fast = pHead;

        while (slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};