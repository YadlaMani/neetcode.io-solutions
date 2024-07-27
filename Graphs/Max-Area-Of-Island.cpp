class Solution {
public:
    int find(vector<vector<int>>&grid,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1){
            return 0;//if out of bound or water return 0
        }
        grid[i][j]=0;//make sure to mark the land so we don't count it again
        //now count one island and go in other direction to search more land
        return 1+find(grid,i+1,j,n,m)+find(grid,i-1,j,n,m)+find(grid,i,j-1,n,m)+find(grid,i,j+1,n,m);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){//whenever we find a land start the traversal
                    ans=max(ans,find(grid,i,j,n,m));
                }
            }
        }
        return ans;
    }
};
