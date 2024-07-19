class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;

        for(int i = 0;i<numRows;i++){
            vector<int> temp_vect(i+1,1);
            answer.push_back(temp_vect);

        }

        for(int i=2;i<numRows;i++){
            int m = answer[i].size();
            for(int j = 1;j<m-1;j++){
                answer[i][j] = answer[i-1][j] + answer[i-1][j-1];
            }
        }
        return answer;
    }
};