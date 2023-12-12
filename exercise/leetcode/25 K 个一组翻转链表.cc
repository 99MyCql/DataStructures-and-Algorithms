/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。



示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]
示例 2：



输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]


提示：
链表中的节点数目为 n
1 <= k <= n <= 5000
0 <= Node.val <= 1000


进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
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
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode *newHead = new ListNode();
        newHead->next = end; // 保证翻转后的链表与后续链表不断开
        ListNode *p = head;
        while (p != end) {
            ListNode* next = p->next; // 关键一步不要忘记
            p->next = newHead->next;
            newHead->next = p;
            p = next;
        }
        return newHead->next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p = head;
        ListNode *q = head;
        for (int i = 0; i < k; i++) {
            p = p->next;
        }
        ListNode *newHead = new ListNode();
        ListNode *newTail = newHead;
        while (1) {
            // 翻转，并拼接到新链表的结尾
            ListNode* tmp = q;
            q = reverse(q, p);
            newTail->next = q;
            newTail = tmp;
            // 前进k
            int i = 0;
            while (i < k && p != nullptr) {
                p = p->next;
                q = q->next;
                i++;
            }
            if (i < k) break;
        }
        return newHead->next;
    }
};

class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode *newHead = new ListNode();
        ListNode *p = head;
        while (p != end) {
            ListNode* next = p->next; // 先保存移除节点的下一个节点，关键一步不要忘记
            p->next = newHead->next;
            newHead->next = p;
            p = next;
        }
        return newHead->next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = new ListNode();
        ListNode *newTail = newHead;
        ListNode *q = head; // q 指向子链表头节点
        ListNode *p = head; // p 指向子链表尾节点的下一个节点
        while (1) {
            // p 前进 k 个节点
            int i = 0;
            while (i < k && p != nullptr) {
                p = p->next;
                i++;
            }
            if (i < k) {
                newTail->next = q; // 将剩余链表拼接到新链表结尾
                break;
            }

            // 翻转子链表，并拼接到新链表的结尾
            newTail->next = reverse(q, p);
            newTail = q; // 翻转之后，子链表头节点变为了尾节点
            q = p; // 将 q 指向下一个子链表头节点
        }
        return newHead->next;
    }
};