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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(1);

        ListNode* ahead = dummy1;
        ListNode* bhead = dummy2;

        while(head != NULL){
            if(head->val < x){
                ahead -> next = new ListNode(head->val);
                ahead = ahead->next;
            }
            else{
                bhead -> next = new ListNode(head->val);
                bhead = bhead->next;
            }
            head = head->next;
        }

        ahead->next = dummy2->next;
        return dummy1->next;
        
    }
};