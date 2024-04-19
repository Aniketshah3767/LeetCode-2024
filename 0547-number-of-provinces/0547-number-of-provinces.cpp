class Solution {
private:
    void dfs(int node, const vector<vector<int>>& adjacencyList, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adjacencyList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjacencyList, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjacencyList(n);

        // Construct the adjacency list from the adjacency matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjacencyList[i].push_back(j);
                    // Optimization: Add the reverse edge only once
                    if (j > i) {
                        adjacencyList[j].push_back(i);
                    }
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adjacencyList, visited);
            }
        }

        return count;
    }
};