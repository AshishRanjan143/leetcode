//using BFS
class Solution {
public:
bool isBipartiteBFS(unordered_map<int,vector<int>> &adj,int i,vector<int> &color,int currColor){
    queue<int> que;
    que.push(i);
    color[i]=currColor;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(int &v:adj[u]){
            if(color[u]==color[v]) return false;
            else if(color[v]==-1){
                color[v]=1-color[u];
                que.push(v);
            }
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> adj;
        for(auto &vec:dislikes){
            int i=vec[0];
            int j=vec[1];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        vector<int> color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!isBipartiteBFS(adj,i,color,1)){
                    return false;
                }
            }
        }
        return true;
        
    }
};
//using DFS
class Solution {
public:
    bool dfs(int node, int currColor,
             vector<vector<int>>& adj,
             vector<int>& color) {

        color[node] = currColor;

        for (int neigh : adj[node]) {
            if (color[neigh] == -1) {
                if (!dfs(neigh, 1 - currColor, adj, color))
                    return false;
            }
            else if (color[neigh] == currColor) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for (auto& edge : dislikes) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, adj, color))
                    return false;
            }
        }

        return true;
    }
};