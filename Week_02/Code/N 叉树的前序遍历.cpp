class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        if (!root) return res;
        res.push_back(root->val);
        for (auto ch : root->children) 
        preorder(ch);
        return res;
    }
}; // 递归
//O(n)

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
    vector<int> preorder(Node* root) {
    vector<int> res;
    stack<Node *> mystack;
    Node* p;
    if (!root) return res;
    mystack.push(root);
    while (!mystack.empty()) {
        p = mystack.top();
        res.push_back(p->val);
        mystack.pop();
        for (int i = p->children.size()-1; i >= 0; --i) {
            mystack.push(p->children[i]);
        }
    }
    return res;
    }
}; // 迭代
//O(n) O(n)

void preorder(Node* root) 
{
    stack<Node*> myStack;
    Node* p;
    if(root==NULL)return;
    myStack.push(root);
    while(!myStack.empty())
    {
        p=myStack.top();
        myStack.pop();
        visit(p);     ////处理
        if(p->right!=NULL){myStack.push(p->right);}
        if(p->left!=NULL){myStack.push(p->left);} 
    }
}//前序遍历模板