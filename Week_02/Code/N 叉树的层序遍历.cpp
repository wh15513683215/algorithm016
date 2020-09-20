/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;


    Node() {}


    Node(int _val) {
        val = _val;
    }


    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        res.emplace_back(vector<int>{root -> val});
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int queSize = que.size();
            vector<int> tmp;
            for (int i = 0; i < queSize; ++i) {
                auto node = que.front();
                que.pop();
                for (auto ch : node -> children) {
                   tmp.emplace_back(ch -> val);
                   que.push(ch);
                }
            }
            if (tmp.size() > 0) {
                res.emplace_back(tmp);
            }
        }
        return res;
    }
}; //bfs O(n) O(n)


class Solution {
public:
    void dfs(Node *root, int level, vector<vector<int>>& res) {
      if (!root) return ;
      if (res.size() == level)
      res.emplace_back();
      res[level].push_back(root -> val);
      for (auto ch : root -> children)
      dfs(ch,level+1,res);
    }
    vector<vector<int>> levelOrder(Node* root) {
     vector<vector<int>> res;
     dfs(root,0,res);
     return res;
    }
}; //递归 O(n) O(n)
