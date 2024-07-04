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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode dummy(0);
        ListNode * temp = &dummy;

        ListNode* curr = head->next;
        while(curr != NULL)
        {
            if(curr->val != 0){
                sum += curr->val;
            }
            else{
                temp->next = new ListNode(sum);
                temp = temp->next;
                sum = 0;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};