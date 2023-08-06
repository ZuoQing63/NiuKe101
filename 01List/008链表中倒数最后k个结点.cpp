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
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        vector<ListNode*> vec;
        while (pHead)
        {
            vec.emplace_back(pHead);
            pHead = pHead->next;
        }
        if (vec.size()<k)return nullptr;
        return vec[vec.size()-k];
    }
};