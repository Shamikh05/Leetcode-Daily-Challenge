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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p1 = head, *prev = NULL, *p2;

        while(p1 and p1->next) {
            p2 = p1->next;
            p1->next = p2->next;

            if(!prev) {
                head = p2;
            } else {
                prev->next = p2;
            }

            p2->next = p1;
            prev = p1;
            p1 = p1->next;
        }

        return head;
    }
};