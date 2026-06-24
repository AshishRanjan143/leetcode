class Solution {
public:
    int result;
    int Dfs(unordered_map<int, vector<int>>& adj, int curr, int parent,
            string& s) {
        int longest = 0;
        int second_longest = 0;
        for (int& child : adj[curr]) {
            if (child == parent)
                continue;
            int child_longest_length = Dfs(adj, child, curr, s);
            if(s[child]==s[curr]) continue;

            if (child_longest_length > second_longest) {
                second_longest = child_longest_length;
            }
            if (second_longest > longest) {
                swap(second_longest, longest);
            }
        }
        int koi_ek_acha = max(longest, second_longest)+1;
        int sirf_root_acha = 1;
        int niche_hi_milgaya = longest + second_longest + 1;
        result = max({result,koi_ek_acha, sirf_root_acha, niche_hi_milgaya});
        return max(koi_ek_acha, sirf_root_acha);
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int, vector<int>> adj;
        result = 0;
        for (int i = 1; i < n; i++) {
            int u = i;
            int v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Dfs(adj, 0, -1, s);
        return result;
    }
};