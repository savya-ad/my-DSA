// Problem link:- https://leetcode.com/problems/number-of-islands/
  
class Solution {
    int numofIsland=0;
public:
    void dfs(vector<vector<char>> &grid, int x, int y){
        int m=grid.size();
        int n= m? grid[0].size(): 0;
        if(x<0||x>=m||y<0||y>=n)
            return;
        if(grid[x][y]=='0'||grid[x][y]=='a')
            return;
        grid[x][y]='a';
        dfs(grid, x+1,y);
        dfs(grid, x-1,y);
        dfs(grid, x,y+1);
        dfs(grid, x,y-1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=m?grid[0].size():0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && grid[i][j]!='a'){
                    numofIsland++;
                    dfs(grid,i,j);
                }
            }
        }
        return numofIsland;
    }
};
