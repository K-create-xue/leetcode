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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root)
        return v;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(node || !st.empty()){
            while(node){
                v.emplace_back(node->val);
                st.push(node);
                node=node->left;
            }
            node=st.top();
            st.pop();
            node=node->right;
        }
        return v;
    }
};


int getSize(struct TreeNode* root){
    if(root==NULL)
    return 0;
    return getSize(root->left)+getSize(root->right)+1;
} 
void _preOrder(struct TreeNode* root,int* arr,int* returnSize){
    if(root){
        arr[(*returnSize)++]=root->val;
        _preOrder(root->left,arr,returnSize);
        _preOrder(root->right,arr,returnSize);
    }
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int sz=getSize(root);
    int* arr=(int*)malloc(sizeof(int)*sz);
    *returnSize=0;
    _preOrder(root,arr,returnSize);
    return arr;
}
