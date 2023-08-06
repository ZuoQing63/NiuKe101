#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next==nullptr)
            return false;
        auto slow = head;
        auto fast = head;

        while (fast&&fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};