/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//recursion
class Solution {
public:
    ListNode* recursion(ListNode* prev, ListNode* node) {
        if (!node) return prev;
        ListNode* next = node->next;
        node->next = prev;
        return recursion(node, next);
    }
    ListNode* reverseList(ListNode* head) {
        return recursion(nullptr, head);
    }
};
