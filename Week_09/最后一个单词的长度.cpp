class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;
        // 去后导0
        while (index >= 0 && isspace(s[index])) --index;
        int cnt = 0;
        // 开始统计
        while (index >= 0 && isalpha(s[index--])) ++cnt;
        return cnt;
    }
};
