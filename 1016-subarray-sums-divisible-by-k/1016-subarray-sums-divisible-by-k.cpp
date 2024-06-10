class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int prefixsum = 0;

        unordered_map<int,int> prefixmap;

        prefixmap[0] = 1;

        for(int num : nums){
            prefixsum += num;

            //calculate the remainder of the prefixsum
            int mod = prefixsum % k;

            if(mod < 0){
                mod += k;
            }
            //cehck if there is already number seen before
            if(prefixmap.find(mod) != prefixmap.end()) {
                count += prefixmap[mod];
                prefixmap[mod]+=1;
            }
            else
                prefixmap[mod] = 1;
        }
        return count;
    }
};