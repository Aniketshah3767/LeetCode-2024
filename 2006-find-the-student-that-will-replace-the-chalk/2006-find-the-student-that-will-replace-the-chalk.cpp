class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
    int n = chalk.size();
    long long total = 0;
    for(int num : chalk){
        total += num;
    }
    int remain = k % total;

    for (int i = 0; i < n; i++) {
        if (remain < chalk[i]) {
            return i;
        }
        remain -= chalk[i];
    }
    return -1;
    }
};