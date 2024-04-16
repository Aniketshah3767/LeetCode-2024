class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;
        int index = 0;
        int maxcount = 0;
        int row = mat.size();
        for(int i = 0 ; i <  row ; i++){
            int count = 0;
            for(int j = 0 ; j < mat[0].size() ; j++){
                if(mat[i][j] == 1)
                    count++;
            }
            if(count>maxcount){
                maxcount = count;
                index = i;
            }
        }

        return{index,maxcount};
    }
};