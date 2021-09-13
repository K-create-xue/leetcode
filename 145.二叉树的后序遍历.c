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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root)
            return v;
        stack<TreeNode*> st;
        TreeNode* node=root;
        TreeNode* prev=NULL; 
        while(node || !st.empty()){
            while(node){
                st.push(node);
                node=node->left;
            }
            TreeNode* top=st.top();
            if(top->right==nullptr || top->right==prev){
                v.push_back(top->val);
                st.pop();
                prev=top;
            }else{
                node=top->right;
            }
        }
        return v;

    // void _postOrder(TreeNode* root,vector<int>* v){
    //     if(root){
    //         _postOrder(root->left,v);
    //         _postOrder(root->right,v);
    //         (*v).push_back(root->val);
    //     }
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> v;
    //     if(root){
    //         _postOrder(root,&v);
    //     }
    //     return v;
    }
};
