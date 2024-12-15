class Solution {
public:
    long long findScore(vector<int>& nums) {
    //     priority_queue<pair<int, int>> pq; 
    //     for(int i = 0 ; i < nums.size() ; i++){
    //         pq.push({nums[i],i});
    //     }

    //     set<int>s;
    //     s.insert(-1);
    //     long long sum = 0;
    //     for(auto it: pq){
    //         auto node = it.top();
    //         int number = node.first;
    //         int index = node.second;
    //         pq.pop();
    //         if(s.find(index) == s.end()){
    //             sum += number;
    //             s.insert(index+1);
    //             s.insert(index-1);
    //         }
    //         else{
    //             continue;
    //         }
    //     }
    // return sum;
    // }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    for (int i = 0; i < nums.size(); ++i) {
        pq.push({nums[i], i}); 
    }

    std::set<int> s;
    s.insert(-1); // Initialize with -1 to handle boundary cases
    long long sum = 0;

    while (!pq.empty()) {
        auto [number, index] = pq.top(); 
        pq.pop();

        if (s.find(index) == s.end()) {
            sum += number;
            s.insert(index - 1);
            s.insert(index + 1); 
        }
    }

    return sum;
}
};