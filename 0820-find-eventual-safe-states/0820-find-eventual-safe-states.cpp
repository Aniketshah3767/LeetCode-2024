class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> revadj[V];
        vector<int> indegree(V, 0);
        
        // Create reverse graph and calculate indegree
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                revadj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        
        // Initialize queue with nodes having 0 indegree
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for (auto it : revadj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};