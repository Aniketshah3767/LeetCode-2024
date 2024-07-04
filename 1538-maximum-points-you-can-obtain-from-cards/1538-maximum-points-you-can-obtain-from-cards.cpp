class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int n = cardPoints.size();
        int rsum = 0;
        int maxi = INT_MIN;

        for(int i = 0 ; i < k;i++)
        {
            lsum += cardPoints[i];
        }
        maxi = lsum;

        int rindex = n - 1;
        for(int i = k - 1 ; i >= 0 ;i--)
        {
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rindex--];
            maxi = max(maxi,lsum+rsum);
        }
    return maxi;
    }
};