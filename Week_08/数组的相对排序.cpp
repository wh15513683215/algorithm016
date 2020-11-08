class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> dp(1001);


    for (int i = 0; i < arr1.size(); ++i) {
        dp[arr1[i]]++;
    }
    int temp = 0;


    for (int i = 0; i < arr2.size(); ++i) {
        while (dp[arr2[i]] > 0) {
            arr1[temp++] = arr2[i];
            dp[arr2[i]]--;
        }
    }


    for (int i = 0; i < dp.size();  ++i) {
        while (dp[i] > 0) {
            arr1[temp++] = i;
            dp[i]--;
        }
    }


      return arr1;
    }
}; // 计数排序

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
      int temp = 0;

      for (int i  = 0; i < arr2.size(); ++i) {
          for (int j = 0; j < arr1.size(); ++j) {
              if (arr1[j] == arr2[i]) {
                  swap(arr1[j], arr1[temp++]);
              }
          }
      }

      sort(arr1.begin() + temp, arr1.end());

      return arr1;
    }
}; //暴力
