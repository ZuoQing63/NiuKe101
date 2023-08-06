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
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        ListNode* result = new ListNode(-1);
        result->next = head;
        if (n == m) {
            return head;
        }
        ListNode* pre = result;
        ListNode* cur = head;
        for (int i = 1; i < m; ++i) {
            pre = cur;
            cur = cur->next;
        }
        ListNode* next = nullptr;
        for (int i = m; i < n; ++i) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return result->next;
    }
};