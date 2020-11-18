class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     // O(N^2) DP
     if (nums.empty()) return 0;
     int n = nums.size();
     vector<int> dp(n, 1);
     int res = 1;


     for (int i = 1; i < n; ++i) {
         for (int j = 0; j < i; ++j) {
             if (nums[j] < nums[i]) {
                 dp[i] = max(dp[i], dp[j] + 1);
             }
         }
         res = max(res, dp[i]);
     }


        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;


        for (int ch : nums) {
            if (!dp.size() || ch > dp.back())
               dp.push_back(ch);
            else
               *lower_bound(dp.begin(), dp.end(), ch) = ch;
        }
     
        return dp.size();
    }
};
