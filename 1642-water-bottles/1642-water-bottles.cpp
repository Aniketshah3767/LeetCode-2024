class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalBottle = numBottles;

        while(numBottles >= numExchange)
        {
            totalBottle += numBottles / numExchange;
            numBottles = (numBottles/numExchange) + (numBottles % numExchange);
        }
        return totalBottle;
    }
};