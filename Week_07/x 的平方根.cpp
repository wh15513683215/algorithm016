class Solution {
public:
    int mySqrt(int x) {
        long long i = 0, j = x / 2 + 1;


        while (i <= j) {
            long long mid = (i + j) / 2;
            long long res = mid * mid;
            if (res == x) return mid;
            else if (res < x) i = mid + 1;
            else j = mid - 1;
        }
        


        return j;
    }
};//二分法 

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        double last = 0, res = 1;
        
        while (res != last) {
            last = res;
            res = (res + x / res) / 2;
        }
        
        return int(res);
     
    }
};// 将res = x进行了算术上的加减乘除然后不断逼近最后得出答案
