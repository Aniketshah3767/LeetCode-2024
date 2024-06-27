class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxval = 0;
        int count = 0;

        for(int i = 0 ; i < arr.size() ;i++)
        {
            maxval = max(maxval, arr[i]);
            if(maxval == i)
                count++;
        }
        
        return count;
    }
};