class Solution {
public:
    int thirdMax(vector<int>& nums) {

        set<int> s(nums.begin(), nums.end());
        if (s.size() < 3)
            return *max_element(s.begin(), s.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : s) {
            pq.push(it);
            while (pq.size() > 3) {
                pq.pop();
            }
        }
        return pq.top();
    }
};