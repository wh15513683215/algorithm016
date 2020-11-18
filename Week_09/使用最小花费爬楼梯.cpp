class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
     int n = cost.size();
     int j = 0, k = min(cost[0], cost[1]);


     for (int i = 2; i < n; ++i) {
         int temp = k;
         k = min(j + cost[i - 1], k + cost[i]);
         j = temp;
     }


     return k;
    }
};
