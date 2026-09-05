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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list1curr = list1;
        ListNode* list2curr = list2;
        ListNode dummy(0); // going to return this one
        ListNode* tail = &dummy; // ampersand to have direct ref

        while(list1curr != NULL && list2curr != NULL)
        {
            if(list1curr->val <= list2curr->val)
            {
                tail->next = list1curr; // point tail (tail is at 0 at first call) to list1curr since its less
                list1curr = list1curr->next; // now iterate it next, we will compare again with next list2 val
                tail = tail->next; // move dummy up so we can keep adding to it
            }

            else 
            {
                tail->next = list2curr;
                list2curr = list2curr->next;
                tail = tail->next;
            }

            if(list1curr == NULL) tail->next = list2curr;
            if(list2curr == NULL) tail->next = list1curr;
        }

        if(list1curr != NULL) tail->next = list1curr;
            else tail->next = list2curr;
        
        return dummy.next;
    }
};
