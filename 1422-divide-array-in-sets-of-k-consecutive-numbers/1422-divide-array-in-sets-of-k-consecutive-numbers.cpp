class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        if(nums.size() % k) return false;

        map<int,int>mp;
        for(auto val:nums) mp[val]++;

        int n = nums.size();
        while(n--)
        {
            for(auto [a, b]:mp)
            {
                for(int i=a;i<a+k;i++)
                {
                    if(mp[i] == 0) return false;
                    mp[i]--;
                    if(mp[i]==0) mp.erase(i);
                }
                break;
            }
        }
        return true;
    }
};