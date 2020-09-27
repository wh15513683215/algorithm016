class Solution {
public:
     vector<string> res;
     
    vector<string> generateParenthesis(int n) {
        string s;
        _generate(0, 0, n, res, s); //只关注当前层的 
        return res; 
    } 
       void _generate(int left, int right, int max, vector<string>& res, string& s) {
        //teminator
         if (left == max && right == max) {
         res.push_back(s);
         return ;
         }
        
        //process
       
        //drill down
        if (left < max) {
        s.push_back('(');
        _generate(left + 1, right, max, res, s);
        s.pop_back();
        }
        if (right < left) {
        s.push_back(')');
        _generate(left, right + 1, max, res, s);
        s.pop_back();
        }
        //reverse state
    } //自顶向下编程

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
