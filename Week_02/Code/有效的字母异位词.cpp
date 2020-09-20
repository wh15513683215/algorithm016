class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.size()!=t.size()) return false;
    int hash[26] = {0};
    for (char ch : s)
    hash[ch -'a']++;
    for (char ch : t){
    if (--hash[ch - 'a']==-1)
     return false;
    }
    return true;
    }//hash 模拟
}; // O(N) O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return  false;
    unordered_map<char,int> map;
    for (char ch : s) map[ch]++;
    for (char ch : t) {
        if (--map[ch] == -1) 
        return false;
    }
    return true;
    }
}; // O(N) O(1)

public:
    bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return  false;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    return s == t;
    }//双Sort
}; // O(NLogn) O(1)