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
//iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (node) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};
