class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        adds(res, "", n, 0);
        return res;
    }
    void adds(vector<string> &res, string str, int left, int right) {
        if (right == 0 && left == 0) {
            res.push_back(str);
            return;
        }
        if (right > 0) adds(res, str + ")", left, right - 1);
        if (left > 0) adds(res, str + "(", left - 1, right + 1);
    }
}; //O(n)O(n)
 //动态规划
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> res(n + 1);
        res[0].push_back("");
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (string &ch : res[j]) {
                    for (string &sh : res[i - j - 1]) {
                        res[i].push_back("(" + sh + ")" + ch);
                    }
                }
            }
        }
        return res[n];
    }
};O(n) O(n)
