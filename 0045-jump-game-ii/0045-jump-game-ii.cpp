class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int minjump = 0;
        int l = 0; int r = 0;
        while(r<n-1){
            int far = 0;
            for(int i = l ; i <= r ;i++){
                far = max(i+nums[i],far);
            }
            l = r+1;
            r = far;
            minjump++;
        }
        return minjump;
    }
};