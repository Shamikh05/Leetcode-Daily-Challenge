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
private:
    ListNode* getSwapped(ListNode *p1) {
        if(!p1 || !p1->next) {
            return p1;
        }

        ListNode *p2 = p1->next;
        p1->next = getSwapped(p2->next);
        p2->next = p1;
        
        return p2;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return getSwapped(head);
    }
};