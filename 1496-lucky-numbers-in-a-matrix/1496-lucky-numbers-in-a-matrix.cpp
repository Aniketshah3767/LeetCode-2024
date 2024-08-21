class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>minrow (m,INT_MAX);
        vector<int>maxcol (n,INT_MIN);

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                minrow[i] = min(minrow[i] , matrix[i][j]);
                maxcol[j] = max(maxcol[j] , matrix[i][j]); 
            }
        }

        vector<int>result;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == minrow[i] && matrix[i][j] == maxcol[j])
                    result.push_back(matrix[i][j]);
            }
        }
        return result;
    }
};