#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
//数组法
class Solution1 {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        if (head == nullptr || head->next == nullptr)
            return true;
        vector<int> vec;
        while (head) {
            vec.emplace_back(head->val);
            head = head->next;
        }
        for (int i = 0 ; i < vec.size() / 2; ++i) {
            if (vec[i] != vec[vec.size() - i - 1])
                return false;
        }
        return true;
    }
};

//step 1：慢指针每次走一个节点，快指针每次走两个节点，快指针到达链表尾的时候，慢指针刚好到了链表中点。
//step 2：从中点的位置，开始往后将后半段链表反转。
//step 3：按照方法三的思路，左右双指针，左指针从链表头往后遍历，右指针从链表尾往反转后的前遍历，依次比较遇到的值。
class Solution2 {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    bool isPail(ListNode* head) {
        // write code here
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast&&fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow);
        fast = head;
        while (slow) {
            if (fast->val != slow->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};