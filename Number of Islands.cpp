class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int ans = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        if(x<0 || x==grid.size() || y<0 || y==grid[x].size() || grid[x][y] != '1')
            return;
        grid[x][y] = '0';
        dfs(x,y+1,grid);
        dfs(x+1,y,grid);
        dfs(x-1,y,grid);
        dfs(x,y-1,grid);
    }
};
