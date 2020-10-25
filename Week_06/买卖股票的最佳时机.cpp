

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mmin = INT_MAX;
        int mmax = 0;



        for (int ch : prices) {
            mmin = min(ch, mmin);
            mmax = max(mmax, ch - mmin);
        }
     


        return mmax;
    }
};
