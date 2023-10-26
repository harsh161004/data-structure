// https://leetcode.com/problems/rotting-oranges/submissions/1084455557/

class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int &mins) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        if(q.empty()) {
            mins = 1;
            return;
        }

        while(!q.empty()) {
            int k = q.size();
            mins++;
            while(k--) {
                vector<int> temp = q.front();
                q.pop();
                int i=temp[0], j=temp[1];
                grid[i][j] = 2;
                if(i+1 < m && !vis[i+1][j] && grid[i+1][j] == 1) {
                    vis[i+1][j] = true;
                    q.push({i+1, j});
                }
                if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1) {
                    vis[i-1][j] = true;
                    q.push({i-1, j});
                }
                if(j+1 < n && !vis[i][j+1] && grid[i][j+1] == 1) {
                    vis[i][j+1] = true;
                    q.push({i, j+1});
                }
                if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1) {
                    vis[i][j-1] = true;
                    q.push({i, j-1});
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), mins = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        bfs(grid, vis, mins);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j ]== 1) return -1;
            }
        }
        return mins-1;

    }
};