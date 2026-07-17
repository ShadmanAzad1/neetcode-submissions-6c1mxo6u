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
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(list1curr != NULL && list2curr != NULL) {
            if(list1curr->val <= list2curr->val) {
                tail->next = list1curr;
                list1curr = list1curr -> next;
                tail = tail->next;
            }

            else {
                tail->next = list2curr;
                list2curr = list2curr->next;
                tail = tail->next;
            }

            if(list1curr != NULL) {
                tail->next = list1curr;
            }
            else {
                tail->next = list2curr;
            }
        }
        if(list1curr != NULL) {
            tail->next = list1curr;
        }
            else {
            tail->next = list2curr;
        }
        return dummy.next;
    }
};
