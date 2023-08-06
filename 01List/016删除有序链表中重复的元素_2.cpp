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
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if (head == nullptr) {
            return nullptr;
        }
        auto res = new ListNode(0);
        res->next = head;
        auto cur = res;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int temp = cur->next->val;
                while (cur->next && cur->next->val == temp)
                    cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return res->next;
    }
};