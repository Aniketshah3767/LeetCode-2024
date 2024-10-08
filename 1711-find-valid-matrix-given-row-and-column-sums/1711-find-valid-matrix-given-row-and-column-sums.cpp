class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = colSum.size();
        int n = rowSum.size();
        vector<vector<int>>matrix(n,vector<int>(m,0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                matrix[i][j] = min(rowSum[i],colSum[j]);
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
            }
        }
    return matrix;
    }
};