class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        vector<int>vis(n,0);

        vis[0] = 1;
        queue<int>q;
        for(int i = 0 ; i < m ; i++){
            q.push(rooms[0][i]);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(vis[node] == 0){
                vis[node] = 1;
                for(int i = 0 ; i < rooms[node].size() ; i++){
                    q.push(rooms[node][i]);
                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 0)
                return false;
        }
        return true;
    }
};