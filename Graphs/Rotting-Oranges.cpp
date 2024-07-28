class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshOra = 0;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {  
                if (grid[i][j] == 2) {
                    q.push({i, j});//push the rotten orange position to the queue
                } else if (grid[i][j] == 1) {
                    freshOra++;//count the fresh oranges
                }
            }
        }
        //all possible direction
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ans = 0;
        
        while (!q.empty() && freshOra > 0) {
            //no.of current nodes
            int siz = q.size();
            for (int i = 0; i < siz; i++) {
                //traverse through queue
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dir) {
                    int nx = x + dx;
                    int ny = y + dy;
                    //checking the cases and if found orange make it root and push to the queue
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        freshOra--;
                        q.push({nx, ny});
                    }
                }
            }
            ans++;
        }
        //if fresh oranges left reutrn -1 else return ans;
        return freshOra > 0 ? -1 : ans;
    }
};
