class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int left=0,right=s.size()-1;
        while(left<=right) {
            if(s[left]=='1')
                left++;
            if(s[right]=='0')
                right--;
            if(left<=right && s[left]=='0' && s[right]=='1')
                swap(s[left],s[right]);
        }
        swap(s[left-1],s[s.size()-1]);
        return s;
    }
};