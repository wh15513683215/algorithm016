class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int pre = 0, pre_buy = INT_MIN;


        for (int ch : prices) {
            int tmp = pre;
            pre = max(pre, pre_buy + ch);
            pre_buy = max (pre_buy, tmp - ch - fee);
        } 


        return pre;
      
    }
};
