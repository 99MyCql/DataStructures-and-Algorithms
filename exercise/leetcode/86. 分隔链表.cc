/*
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。



示例 1：


输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：

输入：head = [2,1], x = 2
输出：[1,2]


提示：

链表中节点的数目在范围 [0, 200] 内
-100 <= Node.val <= 100
-200 <= x <= 200
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *newH = new ListNode();
        newH->next = head;
        ListNode *p = head, *pre = newH;
        ListNode *leftH = new ListNode();
        ListNode *leftP = leftH;
        while (p) {
            if (p->val < x) {
                pre->next = p->next;
                p->next = leftP->next;
                leftP->next = p;
                leftP = leftP->next;
                p = pre->next;
            } else {
                pre = pre->next;
                p = p->next;
            }
        }
        leftP->next = newH->next;
        return leftH->next;
    }

    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode();
        ListNode *right = new ListNode();
        ListNode *p = head, *lp = left, *rp = right;
        while (p) {
            ListNode *next = p->next;
            if (p->val < x) {
                lp->next = p;
                lp = p;
            } else {
                rp->next = p;
                rp = p;
            }
            p = p->next;
        }
        lp->next = right->next;
        rp->next = nullptr;
        return left->next;
    }
};