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
int result;
int solve(TreeNode* root){
    if(root==NULL) return 0;
    int left1=solve(root->left);
    int right1=solve(root->right);
    result=max(result,left1+right1);
    return max(left1,right1)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
        result=INT_MIN;
        if(root==NULL) return 0;
        solve(root);
        return result;
    }
};