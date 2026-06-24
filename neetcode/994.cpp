class Solution {
public:
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> que;
        int fresh = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    que.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }

        if(fresh==0) return 0;

        int minutes = 0;

        while(!que.empty() && fresh>0){
            int sz = que.size();

            while(sz--){
                auto [row,col] = que.front();
                que.pop();

                for(auto &dir : directions){
                    int nr = row + dir[0];
                    int nc = col + dir[1];

                    if(nr>=0 && nr<m && nc>=0 && nc<n &&
                       grid[nr][nc]==1){

                        grid[nr][nc]=2;
                        fresh--;
                        que.push({nr,nc});
                    }
                }
            }

            minutes++;
        }

        return fresh==0 ? minutes : -1;
    }
};