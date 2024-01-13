/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。



示例 1：



输入：head = [1,2,3,4]
输出：[1,4,2,3]
示例 2：



输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]


提示：

链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *newH = new ListNode();
        newH->next = head;
        ListNode *slow = head, *fast = head, *slow_pre = newH;
        while (fast && fast->next) {
            slow_pre = slow_pre->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 链表长度为奇数
        if (fast != nullptr) {
            slow = slow->next;
            slow_pre = slow_pre->next;
        }
        slow_pre->next = nullptr;
        ListNode *tmpH = new ListNode();
        while (slow) {
            ListNode *next = slow->next;
            slow->next = tmpH->next;
            tmpH->next = slow;
            slow = next;
        }
        ListNode *p1 = head, *p2 = tmpH->next;
        while (p2) {
            ListNode *p1_next = p1->next;
            ListNode *p2_next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p1_next;
            p2 = p2_next;
        }
    }
};