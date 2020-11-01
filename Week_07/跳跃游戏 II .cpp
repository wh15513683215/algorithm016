class Solution {
public:
    int jump(vector<int>& nums)
{
    int ans = 0, end = 0, maxPos = 0;
   
    for (int i = 0; i < nums.size() - 1; ++i) {
        maxPos = max(maxPos, i + nums[i]);
        if (i == end) {
            ans++;
            end = maxPos;
        }
    }
    
    return ans;
}
};

	