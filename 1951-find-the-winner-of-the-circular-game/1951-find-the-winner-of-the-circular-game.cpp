class Solution {
public:
    // int winner(vector<bool>& person, int person_left, int n, int index, int k) {
    //     if (person_left == 1) {
    //         for (int i = 0; i < person.size(); i++)
    //             if (person[i] == 0)
    //                 return i;
    //     }

    //     // find the position of person to kill;
    //     int kill = (k - 1) % person_left;
    //     while (kill--) {
    //         index = (index + 1) % n;
    //         while (person[index] == 1) {
    //             index = (index + 1) % n; // skip the elemented person.
    //         }
    //     }
    //     person[index] = 1;

    //     // next alive person.
    //     while (person[index] == 1)
    //         index = (index + 1) % n;

    //     return winner(person, person_left - 1, n, index, k);
    // }

    int winner(int n , int k){
        if(n == 1){
            return 0;
        }

        return (winner(n-1,k) + k) % n;
        
    }
    int findTheWinner(int n, int k) {
        // int person_left = n;
        // int index = 0;
        // vector<bool> person(n, 0);

        // return winner(person, person_left, n, index, k) + 1;
        return winner(n,k) + 1;
    }
};