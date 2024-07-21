class Solution {
private:
    bool canPlaceBalls(vector<int>& position, int dist, int m) {
        int ballsPlaced = 1;
        int lastPosition = position[0];
        
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPosition >= dist) {
                ballsPlaced++;
                lastPosition = position[i];
                if (ballsPlaced >= m) return true;
            }
        }
        
        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();

        int low = 1;
        int high = position[n-1] - position[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(canPlaceBalls(position,mid,m) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    return high;
    }
};