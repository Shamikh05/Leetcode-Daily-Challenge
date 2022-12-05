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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        // Move slow ptr by 1 node and fast ptr by 2 nodes at every iteration. 
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow ptr will point to middle node.
        return slow;
    }
};