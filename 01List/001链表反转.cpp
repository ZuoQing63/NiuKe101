#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//栈
class Solution1
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *ReverseList(ListNode *head)
    {
        // write code here
        stack<ListNode *> stk;
        while (head != nullptr)
        {
            stk.push(head);
            head = head->next;
        }
        if (stk.empty())
        {
            return nullptr;
        }
        ListNode *node = stk.top();
        stk.pop();
        ListNode *result = node;
        while (!stk.empty())
        {
            node->next = stk.top();
            stk.pop();
            node = node->next;
        }
        node->next = nullptr;
        return result;
    }
};

//正规方法：三指针
class Solution2 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        // write code here
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};