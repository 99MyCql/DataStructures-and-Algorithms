/*
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。



示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：


输入：head = [0,1,2], k = 4
输出：[2,0,1]


提示：

链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode *newH = new ListNode();
        newH->next = head;
        int len = 0;
        ListNode *p = head, *last = newH;
        while (p) {
            len++;
            last = p;
            p = p->next;
        }
        int m = len - (k%len);
        p = newH;
        for (int i = 0; i < m; i++) p = p->next;
        last->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        int len = 0;
        ListNode *p = head, *last = head;
        while (p) {
            len++;
            last = p;
            p = p->next;
        }
        int m = len - (k%len);
        p = head;
        for (int i = 0; i < m-1; i++) p = p->next;
        last->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};