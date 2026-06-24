//Approach-1
class Solution {
public:
int maxPath=0;
void solve(TreeNode* root,int steps,bool goleft){
    if(root==NULL) return;
    maxPath=max(maxPath,steps);
    if(goleft){
        solve(root->left,steps+1,false);
        solve(root->right,1,true);
    }else{
        solve(root->right,steps+1,true);
        solve(root->left,1,false);
    }
}
    int longestZigZag(TreeNode* root) {
        solve(root,0,false);
        solve(root,0,true);
        return maxPath;
    }
};
//Approach-2
class Solution {
public:
    int maxPath = 0;
    void solve(TreeNode* root, int right, int left) {
        if (root == NULL)
            return;
        maxPath = max({maxPath, right, left});
        solve(root->left, 0, right + 1);
        solve(root->right, left + 1, 0);
    }
    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);

        return maxPath;
    }
};