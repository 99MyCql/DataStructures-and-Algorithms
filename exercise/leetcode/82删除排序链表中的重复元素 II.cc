/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。



示例 1：


输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
示例 2：


输入：head = [1,1,1,2,3]
输出：[2,3]


提示：

链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序 排列
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
    ListNode* fun(ListNode* head, ListNode* pre) {
        if (head == nullptr) return head;
        if ((head->next != nullptr && head->next->val == head->val) ||
            (pre != nullptr && pre->val == head->val)) {
            return fun(head->next, head);
        }
        head->next = fun(head->next, nullptr);
        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        return fun(head, nullptr);
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newH = new ListNode();
        newH->next = head;
        ListNode *p = head, *pre = newH;
        while (p && p->next) {
            if (p->next && p->next->val == p->val) {
                ListNode *pp = p->next;
                while (pp && pp->val == p->val) {
                    pp = pp->next;
                }
                pre->next = pp;
                p = pp;
            } else {
                pre = pre->next;
                p = p->next;
            }
        }
        return newH->next;
    }
};
