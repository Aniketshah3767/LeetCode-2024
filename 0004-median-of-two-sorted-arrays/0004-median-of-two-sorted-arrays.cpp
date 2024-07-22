class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int ind1 = n/2-1;
        int ind2 = n/2;
        int count = 0;
        int i=0,j=0;
        int index1 = -1;
        int index2 = -1;

        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(count == ind1)  index1 = nums1[i];
                if(count == ind2)  index2 = nums1[i];
                i++;count++;
            }
            else{
                if(count == ind1)  index1 = nums2[j];
                if(count == ind2)  index2 = nums2[j];
                j++;
                count++;
            }
        }
        while(i < n1){
            if(count == ind1)  index1 = nums1[i];
                if(count == ind2)  index2 = nums1[i];
                i++;count++;
        }
        while( j < n2){
            if(count == ind1)  index1 = nums2[j];
                if(count == ind2)  index2 = nums2[j];
                j++;
                count++;
        }
        if(n%2 != 0)
            return index2;
        return (double)((double)(index1+index2))/2.0;
    }
};
