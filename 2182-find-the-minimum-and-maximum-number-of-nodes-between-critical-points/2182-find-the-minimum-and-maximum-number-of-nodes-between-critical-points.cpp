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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // ListNode dummy(0);
        // ListNode *temp = &dummy;
        vector<int> points;
        ListNode* prev = NULL;
        ListNode* curr = head;
        int pos = 0;

        while(curr != NULL && curr->next != NULL)
        {
            if(prev != NULL && curr->next != NULL)
            {
                if((curr->val > prev -> val && curr -> val > curr->next->val)
                || (curr->val < prev -> val && curr -> val < curr->next->val))
                points.push_back(pos);
            }
            prev = curr;
            curr = curr -> next;
            pos++;
        }

        if(points.size() < 2)
        {
            return {-1,-1};
        }

        int mindist = INT_MAX;
        int maxdist = points.back() - points.front();

        for(int i = 1 ; i < points.size() ; i++)
        {
            mindist = min(mindist , points[i] - points[i-1]);
        }
        return {mindist , maxdist};
    }
};