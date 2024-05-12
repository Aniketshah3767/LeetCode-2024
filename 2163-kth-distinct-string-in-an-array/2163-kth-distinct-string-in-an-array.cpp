class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> mp;
        int n = arr.size();

        for(int i =0 ; i < n ;i++){
            mp[arr[i]]++;
        }

        int count = 0;
        for(auto it : arr){
            if(mp[it] == 1){
                count++;

                if(count == k)
                    return it;
            }
        }
        return "";
    }
};