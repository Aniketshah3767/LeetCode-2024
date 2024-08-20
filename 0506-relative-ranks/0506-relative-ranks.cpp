class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        priority_queue<pair<int,int>>pq;

        for(int i = 0 ; i < n ;i++){
            pq.push({score[i],i});
        }
        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        int number = 1;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int index = top.second;
            if(number < 4){
                ans[index] = rank[number-1];
            }
            else{
                ans[index] = to_string(number);
            }
            number++;
        }
        return ans;
    }
};