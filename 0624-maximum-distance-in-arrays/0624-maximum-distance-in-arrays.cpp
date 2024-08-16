class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int small = arrays[0][0];
        int big = arrays[0].back();
        int max_dist = 0;

        for(int i = 1 ; i < arrays.size(); i++){
            max_dist = max(max_dist,abs(arrays[i].back()-small));
            max_dist = max(max_dist,abs(big - arrays[i][0]));
            small = min(small, arrays[i][0]);
            big = max(big,arrays[i].back());
        }
        return max_dist;
    }
};
// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) {
//         int smallest = arrays[0][0];
//         int biggest = arrays[0].back();
//         int max_distance = 0;

//         for (int i = 1; i < arrays.size(); ++i) {
//             max_distance = max(max_distance, abs(arrays[i].back() - smallest));
//             max_distance = max(max_distance, abs(biggest - arrays[i][0]));
//             smallest = min(smallest, arrays[i][0]);
//             biggest = max(biggest, arrays[i].back());
//         }

//         return max_distance;
//     }
// };