//using dfs 
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
int nodes;
void solve(TreeNode* root,int path_max){
    if(root==NULL){
        return;
    }
    if(root->val>=path_max){
        nodes+=1;
    }
    solve(root->left,max(path_max,root->val));
    solve(root->right,max(path_max,root->val));
}
    int goodNodes(TreeNode* root) {
        nodes=0;
        solve(root,INT_MIN);
        return nodes;
        
    }
};
//using bfs
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
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int count=0;
        queue<pair<TreeNode*,int>> que;
        que.push({root,root->val});
        while(!que.empty()){
            auto[node,pathMax]=que.front();
            que.pop();
            if(node->val>=pathMax){
                count++;
            }
            int newMax=max(pathMax,node->val);
            if(node->left){
                que.push({node->left,newMax});
            }
            if(node->right){
                que.push({node->right,newMax});
            }
        }
        return count;
        
    }
};