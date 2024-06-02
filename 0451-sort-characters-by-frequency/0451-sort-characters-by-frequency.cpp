class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int>mpp;
        for(int i = 0 ; i < s.size() ; i++){
            mpp[s[i]]++;
        }

        // priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        priority_queue<pair<int, char>> pq;
        
        for(auto i = mpp.begin() ; i != mpp.end() ; i++){
            pq.push({i->second,i->first});
        }

        while(!pq.empty()){
           char c = pq.top().second;
           int count = pq.top().first;
           pq.pop();
           ans.append(count,c);
        }
        return ans;
    }
};