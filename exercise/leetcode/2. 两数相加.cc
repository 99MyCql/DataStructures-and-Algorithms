/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

示例 1：


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
 

提示：

每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-two-numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *p1 = l1, *p2 = l2, *p = head;
        int num = 0;
        while (p1 != nullptr || p2 != nullptr) {
            int sum = num;
            if (p1 != nullptr) {
                sum += p1->val;
                p1 = p1->next;
                if (p2 != nullptr) {
                    sum += p2->val;
                    p2 = p2->next;
                }
            } else {
                sum += p2->val;
                p2 = p2->next;
            }
            p->next = new ListNode(sum%10);
            num = sum/10;
            p = p->next;
        }
        if (num != 0) {
            p->next = new ListNode(num);
        }
        return head->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        int add = 0;
        ListNode *newHead = new ListNode();
        ListNode *p = newHead;
        while (p1 || p2 || add) {
            if (p1) add += p1->val;
            if (p2) add += p2->val;
            p->next = new ListNode(add%10);
            add /= 10;
            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
            p = p->next;
        }
        return newHead->next;
    }
};