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
        ListNode* dummy2 = new ListNode(0);
        ListNode* atemp = dummy1;
        ListNode* btemp = dummy2;

        while(head!=NULL){
            if(head->val < x){
                atemp -> next = new ListNode(head->val);
                atemp= atemp -> next;
            }
            else{
                btemp -> next = new ListNode(head->val);
                btemp = btemp -> next;
            }
            head = head -> next;
        }
        atemp ->next = dummy2 -> next;
        return dummy1->next;
    }
};