class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1)
        return 0;
       int pre_pre = 0, pre_no = 0, pre_yes = -prices[0];
        
// pre_pre = 表示 dp[i-2][0]
// pre_no，表示 dp[i-1][0]
//pre_yes，表示 dp[i-1][1]



        for (int i = 1; i < prices.size(); i++) {
            int temp = pre_no;
            pre_no = max(pre_no, pre_yes + prices[i]);
            pre_yes = max(pre_yes, pre_pre - prices[i]);
            pre_pre = temp;
        }
      
        return pre_no;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3,INT_MIN));
        dp[0][0] = 0;
        
        
        for (int i = 0; i < n; ++i) {
            dp[i + 1][0] = max(dp[i][0], dp[i][2]);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] - prices[i]);
            dp[i + 1][2] = dp[i][1] + prices[i];
        }
        
        return max(dp[n][0], dp[n][2]);
        
    }
};
