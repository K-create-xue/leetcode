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
        vector<int> v;
        if(!root)
        return v;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(node || !st.empty()){
            while(node){
                st.push(node);
                node=node->left;
            }
            node=st.top();
            st.pop();
            v.push_back(node->val);
            node=node->right;
        }
        return v;
    }
};

class Solution {
public:
    void _inOrder(TreeNode* root,vector<int>* v){
        if(root==nullptr)
        return;
        _inOrder(root->left,v);
        (*v).push_back(root->val);
        _inOrder(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root){
            _inOrder(root,&v);
        }
        return v;
    }
};
