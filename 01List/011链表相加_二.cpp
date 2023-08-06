#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//先反转，相加后，结果再反转
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if (head1 == nullptr)
            return head2;
        if (head1 == nullptr)
            return head1;
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        int8_t adds = 0;
        while (head1 || head2 || adds) {
            int val1 = head1 == nullptr ? 0 : head1->val;
            int val2 = head2 == nullptr ? 0 : head2->val;
            head->next = new ListNode((val1 + val2 + adds) % 10);
            head = head->next;
            adds = (val1 + val2 + adds) / 10;
            if (head1)
            head1 = head1->next;
            if (head2)
            head2 = head2->next;
        }
        return reverseList(res->next);
    }
};