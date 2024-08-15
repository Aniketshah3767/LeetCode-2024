class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        int maxi = 0;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        int i = 0;
        while(i<n){
            long long temp = spells[i];
            int start = 0;
            int pos = m;
            int end = m - 1;
            while(start <= end){
                int mid = start + (end - start)/2;
                if(potions[mid] * temp >= success){
                    pos = mid;
                    end = mid - 1;
                }
                else{
                    start = mid +1;
                }
            }
            ans.push_back(m - pos);
            i++;
        }
        return ans;
    }
};