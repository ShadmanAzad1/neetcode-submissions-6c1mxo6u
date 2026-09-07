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
    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL) return;
        
        ListNode* l1 = head;
        ListNode* l2 = head;
        ListNode* middle = NULL;

        while(l1->next != NULL && l2->next != NULL && l2->next->next != NULL)
        {
            l1 = l1->next;
            l2 = l2->next->next;
        }

        middle = l1;

        ListNode* second = middle->next;
        middle->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = second;
        ListNode* nextnode = NULL;
        while(curr != NULL)
        {
            nextnode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextnode;
        }

        if(prev == NULL) return;

        l1 = head;
        l2 = prev;
        ListNode* l1next = l1->next;
        ListNode* l2next = l2->next;
        while(l1 != NULL && l2 != NULL) 
        {
            l1->next = l2;
            l2->next = l1next;
            l1 = l1next;
            l2 = l2next;
            if(l1 != NULL) l1next = l1->next;
            if(l2 != NULL) l2next = l2->next;
        }
    }
};