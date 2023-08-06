#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */
    struct cmp
    {
        bool operator()(ListNode *p1, ListNode *p2)
        {
            return (p1->val > p2->val);
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // write code here
        if (lists.empty())
        {
            return nullptr;
        }
        ListNode *result = new ListNode(0);
        ListNode *head = result;
        priority_queue<ListNode *, vector<ListNode *>, cmp> qp;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] != nullptr)
            {
                qp.push(lists[i]);
            }
        }
        while (!qp.empty())
        {
            auto temp = qp.top();
            qp.pop();
            head->next = temp;
            head = head->next;
            if (temp->next != nullptr)
                qp.push(temp->next);
        }
        return result->next;
    }
};