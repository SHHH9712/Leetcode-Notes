class Solution {
private:
    int row;
    int col;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        row = grid.size();
        if(row==0) return 0;
        col = grid[0].size();
        
        vector<int> use(col, 0);
        vector<vector<int>> used(row, use);
        
        
        int result = 0;
        while(true){
            queue<vector<int>> que;
            vector<int> new_land = find_1(grid, used);
            if(new_land[0]==-1) break;
            que.push(new_land);
            used[que.front()[0]][que.front()[1]] = 1;
            result++;
            
            while(que.size()>0){
                int r = que.front()[0];
                int c = que.front()[1];
                que.pop();

                for(vector<int> d : dir){
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if(nr<0 || nr>=row || nc<0 || nc>=col || grid[nr][nc]=='0' || used[nr][nc]==1) continue;
                    vector<int> point = {nr, nc};
                    que.push(point);
                    used[nr][nc] = 1;
                }
            }
        }
        
        
        
        return result;
    }
    
    vector<int> find_1(vector<vector<char>>& grid, vector<vector<int>>& used){
        int r = grid.size();
        int c = grid[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                char val = grid[i][j];
                int va = val - '0';
                cout << va << "," << used[i][j] << endl;
                if(va==1 && used[i][j]==0){
                    vector<int> point = {i, j};
                    return point;
                }
            }
        }
        vector<int> point = {-1, -1};
        return point;
    }
    
    
};