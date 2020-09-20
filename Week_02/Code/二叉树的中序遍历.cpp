class Solution {
public:
    void inorder(TreeNode *root,vector<int>& res) {
        if (!root) return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> res;
       inorder(root,res);
       return res;
    }
}; //递归 O（n）O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        std::stack<TreeNode*> toVisit;
        while(1) {
            while(root) { 
                toVisit.push(root); 
                root=root->left; 
            }
            if(toVisit.empty()) break;
            root=toVisit.top(); toVisit.pop();
            nodes.push_back(root->val);
            root=root->right;
        }
        return nodes;
    }
}; //迭代

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
             vector<int> result;
        stack<pair<TreeNode*, int> > stk;
        stk.push((make_pair(root, 0)));
        
        while(!stk.empty()) {
            auto [node, type] = stk.top();
            stk.pop();
            if(node == nullptr) continue;
            if(type == 0) {
                stk.push(make_pair(node->right, 0));
                stk.push(make_pair(node, 1));
                stk.push(make_pair(node->left, 0));
            }
            else result.emplace_back(node->val);
        }
        return result;
    }
}; //颜色标识法

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    nodes.push_back(root -> val);
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    } //Morris
};//O(2N) O(1)


