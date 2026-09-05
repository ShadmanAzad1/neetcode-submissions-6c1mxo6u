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

    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
        return a->val > b-> val; // since a has lower priority, we check if its less
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode dummy(0);
        ListNode* tail = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != nullptr)
            {
                pq.push(lists[i]);
            }
        }

        while(!pq.empty())
        {   

            ListNode * smallest = pq.top();
            pq.pop();

            if(smallest->next != nullptr)
            {
                pq.push(smallest->next);
            }

            tail->next = smallest;
            tail = tail->next;
        }

        return dummy.next;
    }
};
