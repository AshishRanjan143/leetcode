class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> que;
        int steps = 0;
        que.push(entrance);
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[entrance[0]][entrance[1]] = true;
        while (!que.empty()) {
            int n1 = que.size();
            while (n1--) {
                vector<int> temp = que.front();
                que.pop();
                if ((temp[0] == 0 || temp[0] == m - 1 || temp[1] == 0 ||
                     temp[1] == n - 1) &&
                    !(temp[0] == entrance[0] && temp[1] == entrance[1]))
                    return steps;
                for (auto& i : dir) {
                    int new_row = temp[0] + i[0];
                    int new_col = temp[1] + i[1];
                    if (new_row < m && new_col < n && new_row >= 0 &&
                        new_col >= 0 && maze[new_row][new_col] == '.' &&
                        !visited[new_row][new_col]) {
                        que.push({new_row, new_col});
                        visited[new_row][new_col] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};