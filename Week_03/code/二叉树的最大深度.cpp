/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int deepth = 0;
        queue<TreeNode*> myque;
        myque.push(root);
        while (!myque.empty()) {
          int mysize = myque.size();
          deepth++;
          for (int i = 0; i < mysize; ++i) {
              TreeNode* tmp = myque.front();
              myque.pop();
              if (tmp -> left) myque.push(tmp -> left);
              if (tmp -> right) myque.push(tmp -> right);
          }
        }
        return deepth;
    }
}; //O(n) O(n) 层序遍历迭代

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root -> right), maxDepth(root -> left)) + 1;
    }
}; //O(n) O(n) 递归
