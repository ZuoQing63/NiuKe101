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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        ListNode* tail = head;
        for (int i = 0; i<k;++i)
        {
            if (tail == nullptr)
            {
                return head;
            }
            tail = tail->next;           
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur!=tail)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        head->next = reverseKGroup(tail, k);
        return pre;
    }
};