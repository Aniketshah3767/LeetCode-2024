class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int maxproduct = 0;
        // for(int i = 0 ; i < nums.size()-1 ; i++){
        //     int product = 1;
        //     for(int j = i+1 ; j < nums.size() ; j++){
        //         product = ((nums[i]-1)*(nums[j]-1));
        //         maxproduct = max(maxproduct,product);
        //     }
        // }
        // return maxproduct;
        // priority_queue < int, vector<int>, greater<int> > pq;
        priority_queue<int>pq;
        for(auto it : nums){
            pq.push(it);
        }

        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        return (first-1)* (second -1); 
    }
};