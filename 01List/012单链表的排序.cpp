#include <bits/stdc++.h>
#include <queue>
#include <vector>
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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    struct cmp {
        bool operator()(ListNode* p1, ListNode* p2) {
            return p1->val > p2->val;
        }
    };
    ListNode* sortInList(ListNode* head) {
        // write code here
        if (head == nullptr)
            return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> qp;            
        while (head) {
            qp.push(head);
            head = head->next;
        }
        ListNode* res = new ListNode(0);
        auto node = res;
        while (!qp.empty())
        {
            auto temp = qp.top();
            qp.pop();
            node->next = temp;
            node = node->next;
        }
        node->next = nullptr;
        return res->next;
    }
};