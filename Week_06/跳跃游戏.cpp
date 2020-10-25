class Solution {
public:
    bool canJump(vector<int>& nums) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) return false;
        k = max (k, i + nums[i]);
    }
    return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (nums[i] >= n - i)
        n = i;
    }
    return n == 0 ? 1 : 0;
    }
};
