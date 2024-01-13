/*
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。



示例1：



输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]
示例2：

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[8,0,7]
示例3：

输入：l1 = [0], l2 = [0]
输出：[0]


提示：

链表的长度范围为 [1, 100]
0 <= node.val <= 9
输入数据保证链表代表的数字无前导 0


进阶：如果输入链表不能翻转该如何解决？
*/
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* l) {
        ListNode *head = new ListNode();
        ListNode *p = l;
        while (p != nullptr) {
            ListNode *nxt = p->next;
            p->next = head->next;
            head->next = p;
            p = nxt;
        }
        return head->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *res = new ListNode();
        ListNode *p1 = l1, *p2 = l2, *p = res;
        int add = 0;
        while (p1 && p2) {
            printf("p1:%d, p2:%d\n", p1->val, p2->val);
            int sum = p1->val + p2->val + add;
            p->next = new ListNode(sum%10);
            add = sum/10;
            p = p->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1) {
            int sum = p1->val + add;
            p->next = new ListNode(sum%10);
            add = sum/10;
            p = p->next;
            p1 = p1->next;
        }
        while (p2) {
            int sum = p2->val + add;
            p->next = new ListNode(sum%10);
            add = sum/10;
            p = p->next;
            p2 = p2->next;
        }
        if (add) {
            p->next = new ListNode(add);
        }
        return reverse(res->next);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *res = new ListNode();
        ListNode *p1 = l1, *p2 = l2, *p = res;
        int add = 0;
        while (p1 || p2 || add) {
            // printf("p1:%d, p2:%d\n", p1->val, p2->val);
            if (p1) add += p1->val;
            if (p2) add += p2->val;
            p->next = new ListNode(add%10);
            add = add/10;
            p = p->next;
            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
        }
        return reverse(res->next);
    }
};