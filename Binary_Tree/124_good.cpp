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
int maxSum;
int solve(TreeNode* root){
    if(!root) return 0;
    int left_subtree=solve(root->left);
    int right_subtree=solve(root->right);
    int koi_ek_acha=max(left_subtree,right_subtree)+root->val;
    int bs_root_acha=root->val;
    int niche_hi_milgaya_ans=left_subtree+right_subtree+root->val;
    maxSum=max({maxSum,koi_ek_acha,bs_root_acha,niche_hi_milgaya_ans});
    
    return max(koi_ek_acha,bs_root_acha);
}
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);
        return maxSum;
    }
};