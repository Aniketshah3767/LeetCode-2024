class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i = 0 ; i < nums.size() ;i++){
            pq.push({nums[i],i});
        }

        vector<pair<int,int>>topk;
        for(int i = 0 ; i < k ; i++){
            topk.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }


        sort(topk.begin(),topk.end());

        for(auto it : topk){
            ans.push_back(it.second);
        }
        return ans;
    }
};