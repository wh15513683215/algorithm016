class Solution {
public:
    vector<int> countBits(int num) {
    vector<int> res(num + 1);


    for(int i = 1; i <= num; i++) {
       res[i] = res[i >> 1] + (i & 1);
    } 


    return res;
    }
}; //位运算

class Solution {
public:
    vector<int> countBits(int num) {
    vector<int> res(num + 1);
    res[0] = 0;

    for(int i = 1; i <= num; i++) {
        if (i % 2 == 1) {
            res[i] = res[i - 1] + 1;
        }

        if (i % 2 == 0) {
            res[i] = res[i / 2];
        }
    }

    return res;
    }
}; //奇偶


