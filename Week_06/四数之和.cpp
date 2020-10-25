class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (nums.size() < 4) 
    return res;


    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 &&nums[i] == nums[i - 1])
        continue;
        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1])
            continue;
            int a = j + 1;  int b = n - 1;
            
            while (a < b) {
                  int sum = nums[i] + nums[j] + nums[a] + nums[b];
                  if (sum > target)  while (a < b && nums[b] == nums[--b]);
                  else if (sum < target) while (a < b && nums[a] == nums[++a]);
                  else {          
                      res.push_back({nums[i], nums[j], nums[a], nums[b]});
                      while (a < b && nums[b] == nums[--b]);        
                      while (a < b && nums[a] == nums[++a]);
                  }
            }
        }
    }
    return res;
    }
};
//双指针法夹逼
	