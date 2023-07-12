/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

 

示例 1：


输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：


输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105
 

进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
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
    ListNode* sortList(ListNode* head) {
        ListNode *p = head;
        int n = 0;
        while (p != nullptr) {
            p = p->next;
            n++;
        }
        return sortListFun(head, n);
    }

    ListNode* sortListFun(ListNode* head, int n) {
        if (n == 0) return nullptr;
        if (n == 1) {
            head->next = nullptr;
            return head;
        }

        ListNode *p = head;
        for (int i = 0; i < n/2; i++) {
            p = p->next;
        }
        ListNode *l = sortListFun(head, n/2);
        ListNode *r = sortListFun(p, n-n/2);

        ListNode *newHead = new ListNode(0);
        p = newHead;
        while (l != nullptr && r != nullptr) {
            if (l->val < r->val) {
                p->next = l;
                l = l->next;
            } else {
                p->next = r;
                r = r->next;
            }
            p = p->next;
        }
        while (l != nullptr) {
            p->next = l;
            p = p->next;
            l = l->next;
        }
        while (r != nullptr) {
            p->next = r;
            p = p->next;
            r = r->next;
        }
        return newHead->next;
    }
};