class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        vector<string>ans;
        for(auto it:words){
            mpp[it]++;
        }

        priority_queue<pair<int,string>>pq;
        for(auto i = mpp.begin() ; i != mpp.end() ; i++){
            pq.push({-i->second , i->first});
        // for(auto it:mpp){

        //     pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(k--){
            ans.insert(ans.begin(),pq.top().second);
            pq.pop();
        }
        return ans;
    }
};