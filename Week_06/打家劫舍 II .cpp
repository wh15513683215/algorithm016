class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
        return 0;
        int n = nums.size();
        if (n < 4)
        return  *max_element(nums.begin(), nums.end());
   
        
        
        int pre_1 = nums[0], now1 = max(nums[0], nums[1]);
        int pre_2 = nums[1], now2 = max(nums[1], nums[2]);
        for (int i = 2; i < n - 1; ++i) {
            int temp = now1;
            now1 = max(pre_1 + nums[i], now1);
            pre_1 = temp;
        }
        for (int i = 3; i < n; ++i) {
            int temp = now2;
            now2 = max(pre_2 + nums[i], now2);
            pre_2 = temp;
        }
        
        return max(now1, now2);
    }


};
