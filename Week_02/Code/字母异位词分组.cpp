class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<double,vector<string>> hash;
    double a[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    for (string& s : strs) {
        double l=1;
   for (auto &c :s)
    l*=a[c-'a'];
    hash[l].push_back(s);
    }
    vector<vector<string>> res;
    for (auto& k : hash) 
    res.push_back(k.second);
    return res;
    }//哈希
};//O(N*k) O(N) k为a的size

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> map;
    vector<vector<string>> res;
    for (auto &ch : strs) {
        string s = ch;
        sort(ch.begin(),ch.end());
        map[ch].push_back(s);
    }
    for (auto &ch : map)
    res.push_back(ch.second);
    return res;
    }//sort
};//O(N*klogk) O(N) 