class Solution {
public:
    int climbStairs(int n) {
        int p = 0,q = 0, g = 1;
     for (int i = 1;i<=n; ++i) {
         p = q;
         q = g;
         g = p + q;
     }
     return g;
    }
};//滚动数组