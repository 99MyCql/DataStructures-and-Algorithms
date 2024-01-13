/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。



示例 1：


输入：head = [1,2,2,1]
输出：true
示例 2：


输入：head = [1,2]
输出：false


提示：

链表中节点数目在范围[1, 105] 内
0 <= Node.val <= 9


进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode *p = head;
        while (p) {
            n++;
            p = p->next;
        }
        ListNode *leftH = new ListNode();
        p = head;
        for (int i = 0; i < n/2; i++) {
            ListNode *next = p->next;
            p->next = leftH->next;
            leftH->next = p;
            p = next;
        }
        ListNode *leftP = leftH->next;
        if (n%2 == 1) p = p->next;
        while (p) {
            if (leftP->val != p->val) return false;
            leftP = leftP->next;
            p = p->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *newH = new ListNode();
        newH->next = head;
        ListNode *slow = head, *fast = head;
        ListNode *leftH = new ListNode();
        while (fast && fast->next) {
            ListNode *pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            newH->next = pre->next;
            pre->next = leftH->next;
            leftH->next = pre;
        }
        ListNode *p1 = newH->next, *p2 = leftH->next;
        if (fast != nullptr) p1 = p1->next; // 链表长度为奇数
        while (p1 && p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};