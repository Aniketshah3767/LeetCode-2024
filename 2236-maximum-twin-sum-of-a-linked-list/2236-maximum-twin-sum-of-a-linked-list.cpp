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
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode* curr = head;
        while(curr != NULL){
            st.push(curr->val);
            curr = curr->next;
        }
        int maxi = INT_MIN;
        curr = head;
        while(curr != NULL){
            int sum = curr->val + st.top();
            st.pop();
            maxi = max(maxi,sum);
            curr = curr->next;
        }
        return maxi;
    }
};