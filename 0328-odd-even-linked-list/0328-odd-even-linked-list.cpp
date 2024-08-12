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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0); 
        int count = 1;
        ListNode* even = dummy1;
        ListNode* odd = dummy2;
        ListNode* temp = head;

        while(temp){
            if(count%2==0){
                even->next = temp;
                even = even->next;
            }
            else{
                odd->next=temp;
                odd = odd->next;
            }
            temp = temp->next;
            count++;
        }

        odd->next = dummy1->next;
        even->next = NULL;
        return dummy2->next;

        // if(!head || !head->next ||!head->next->next){
        //     return head;
        // }

        // ListNode* dummy1 = new ListNode(-1);
        // ListNode* dummy2 = new ListNode(-1);

        // ListNode* odd = head;
        // ListNode* even = head->next;
        // ListNode* even_start = head->next;

        // while(odd->next && even->next){
        //     odd->next = even->next;
        //     even->next = odd->next->next;
        //     odd=odd->next;
        //     even=even->next;
        // }
        // odd->next = even_start;
        // return head;

        
    }
};