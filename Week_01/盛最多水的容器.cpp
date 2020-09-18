class Solution {
public:
    int maxArea(vector<int>& height) {
      int i=0,j=height.size()-1;
      int res = 0;
      for (int a =0;a<height.size();++a) {
          int rex = min(height[i],height[j])*(j-i);
          res = max(res,rex);
          if (height[i]<height[j]) 
          i++;
          else j--;
      }
      return res;
    }
}; //O(n) O(1);