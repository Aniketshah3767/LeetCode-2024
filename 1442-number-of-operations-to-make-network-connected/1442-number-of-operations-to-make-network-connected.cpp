#include <vector>

class DisjointSet {
public:
    std::vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, std::vector<std::vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        DisjointSet ds(n);
        int countExtra = 0;
        for (const auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            if (ds.findParent(u) == ds.findParent(v)) {
                countExtra++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }

        int componentCount = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                componentCount++;
            }
        }
        
        int requiredConnections = componentCount - 1;
        if (countExtra >= requiredConnections)
            return requiredConnections;
        return -1;
    }
};