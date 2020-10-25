class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MAX, secondBuy = INT_MAX, firstProfit = 0, secondProfit = 0;


        for (int ch: prices) {
            firstBuy = min(ch, firstBuy);
            firstProfit = max(firstProfit, ch - firstBuy);
            secondBuy = min(secondBuy, ch - firstProfit);
            secondProfit = max(secondProfit, ch - secondBuy);
        }
    


        return secondProfit;
    }
};
