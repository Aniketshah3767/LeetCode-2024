class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>mpp;
        for(auto i : words){
            mpp[i]++;
        }

        // priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        priority_queue<pair<int, string>> pq;
        for(auto i = mpp.begin() ; i != mpp.end() ;i++){
            pq.push({-i->second , i->first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.insert(ans.begin(),pq.top().second);
            pq.pop();
        }
        return ans;
    }
};