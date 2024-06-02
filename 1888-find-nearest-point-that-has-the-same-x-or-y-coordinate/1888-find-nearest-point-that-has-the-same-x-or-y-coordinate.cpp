class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0 ; i < points.size() ; i++){
            if(points[i][0] == x || points[i][1] == y){
                int md = abs(points[i][0] - x) + abs(points[i][1]- y);
                pq.push({md,i});
            }
        }

        if(pq.empty())
            return -1;
        return pq.top().second;        
    }
};