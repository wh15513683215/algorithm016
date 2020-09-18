class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for (int i = 0; i< nums.size(); ++i) {
        if (map.find(target-nums[i])!=map.end()) {
            return {map[target-nums[i]],i};
        }
        map[nums[i]] = i;
    }
     return {};
    } 
};//O(n) O(1) 哈希
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; 
        vector<int> temp;
        temp=nums;
        int n=temp.size();
       sort(temp.begin(),temp.end());//排序
       int i=0,j=n-1;
       while(i<j){  
           if(temp[i]+temp[j]>target)j--;
          else if(temp[i]+temp[j]<target)i++;
          else break; 
       } 
      for(int k=0;k<n;++k){
          if(nums[k]==temp[i]){
              ans.push_back(k);     
          }
         else if(nums[k]==temp[j]){
              ans.push_back(k);         
          }
      }
        return ans;
    }
};//O(n) O(1); 双指针