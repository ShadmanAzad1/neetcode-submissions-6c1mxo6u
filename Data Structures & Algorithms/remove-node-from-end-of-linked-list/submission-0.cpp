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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head== NULL) return NULL;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;;
        ListNode* second = dummy;

        while(n > 0 && first->next != NULL && second->next != NULL)
        {
            second = second->next;
            n--;
        }
        
        while(second->next != NULL)
        {
            first = first->next;
            second = second->next;
        }

        first->next = first->next->next;

        return dummy->next;
    }
};
