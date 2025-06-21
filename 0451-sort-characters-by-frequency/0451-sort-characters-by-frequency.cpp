class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int>mpp;
        for(auto it : s){
            mpp[it]++;
        }

        priority_queue<pair<int,char>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }

        while(!pq.empty()){
            char c = pq.top().second;
            int count = pq.top().first;
            pq.pop();
            ans.append(count,c);
        }
        return ans;


        // string ans = "";
        // unordered_map<char,int>mpp;
        // for(auto it : s){
        //     mpp[it]++;
        // }

        // priority_queue<pair<int,int>>pq;
        // for(auto it : mpp){
        //     pq.push({it.second, it.first});
        // }

        // while(!pq.empty()){
        //     char c = pq.top().second;
        //     int count = pq.top().first;
        //     pq.pop();
        //     ans.append(count,c);
        // }
        // return ans;
    }
};