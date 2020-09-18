class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      std::sort(nums.begin(),nums.end());
      for (int i = 0; i < nums.size(); i++) {
          int target = -nums[i];
          int front = i + 1;
          int back =nums.size()-1;
          if (target<0) {
              break;
          }
          while (front<back) {
              int sum =nums[front] + nums[back];
              if (target > sum) front++;
            else  if (target < sum) back--; 
            else {
                vector<int> temp(3,0);
                temp[0] = nums[i];
                temp[1] = nums[front];
                temp[2] = nums[back];
                res.push_back(temp);
                while (front<back&&nums[back] == temp[2] ) back--;
                while (front<back&&nums[front] == temp[1]) front++;
            }
            while (i+1<nums.size()&&nums[i+1]==nums[i]) i++;
          }       
      }
      return res;
    }
};//双指针
