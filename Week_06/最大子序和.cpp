class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;


        for (int ch : nums) {
            sum += ch;
            res = max(sum, res);
            if (sum < 0)
               sum = 0;
        }


        return res;
    }
};
