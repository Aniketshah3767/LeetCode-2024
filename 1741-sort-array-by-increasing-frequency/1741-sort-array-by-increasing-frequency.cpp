class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }

        vector<int>ans;

        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue<pair<int,int>>pq;


        for(auto &it: mpp){
            pq.push({-1 * it.second,it.first});
        }

        while(!pq.empty()){
            int ele = pq.top().second;
            int freq = -1 * pq.top().first;
            pq.pop();

            for(int i = 0 ; i < freq ;i++){
                ans.push_back(ele);
            }
        }
        return ans;
        
    }
};