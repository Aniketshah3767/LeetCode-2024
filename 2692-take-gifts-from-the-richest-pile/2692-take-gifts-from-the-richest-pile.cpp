class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (auto it : gifts) {
            pq.push(it);
        }
        long long sum = 0;

        for (int i = 0; i < k; i++) {
            int top = pq.top();
            int temp = floor(sqrt(top));
            pq.pop();

            pq.push(temp);
        }

        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};