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
    TreeNode* invertTree(TreeNode* root) {
    if (root) {
        invertTree(root -> left);
        invertTree(root -> right);
        std::swap(root -> left, root -> right);
    }
    return root;
}
}; // 递归 O(n) 

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
    TreeNode* invertTree(TreeNode* root) {
     stack<TreeNode*> mystk;
     mystk.push(root);
     while (!mystk.empty()) {
         TreeNode* tmp = mystk.top();
         mystk.pop();
         if (tmp) {
         swap(tmp -> left, tmp -> right);
         if (tmp -> left)  mystk.push(tmp ->left);
         if (tmp -> right)  mystk.push(tmp -> right);       
         }   
     }
     return root;
    }
}; //  O(n) O(n) 迭代
