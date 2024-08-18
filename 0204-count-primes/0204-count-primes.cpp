class Solution {
    // private:
    // bool isPrime(int n){
    //     for(int i = 2 ; i < n ; i++){
    //         if(n%i == 0)
    //             return false;
    //     }
    //     return true;
    // }
public:
    int countPrimes(int n) {
        // int count = 0;
        // for(int i = 2 ; i < n ; i++){
        //     if(isPrime(i)){
        //         count++;
        //     }
        // }
        // return count;
        if (n <= 2)
            return 0; // No primes less than 2
        vector<bool> prime(n, true);

        // Step 2: Mark non-prime numbers
        for (int p = 2; p * p < n; p++) {
            if (prime[p]) {
                for (int i = p * p; i < n; i += p) {
                    prime[i] = false;
                }
            }
        }

        // Step 3: Count prime numbers
        int count = 0;
        for (int p = 2; p < n; p++) {
            if (prime[p]) {
                count++;
            }
        }

        return count;
    }
};