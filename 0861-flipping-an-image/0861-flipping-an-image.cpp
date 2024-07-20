class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>ans;

        for(int i = 0 ; i < n ; i++){
            vector<int>ini;
            for(int j = 0 ; j < m ; j++){
                ini.push_back(image[i][j]);
            }
            reverse(ini.begin(),ini.end());
            ans.push_back(ini);
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(ans[i][j] == 1){
                    ans[i][j] = 0;
                }
                else{
                    ans[i][j] = 1;
                }
            }
        }
        return ans;
    }
};