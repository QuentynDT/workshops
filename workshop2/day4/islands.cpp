
//Find number of islands
#include <bits/stdc++.h>
using namespace std;
int numIsland(vector<vector<int>>& grid){
    const int m = grid.size(), n = grid[0].size();
    auto dfs = [&](this auto self, int r, int c) -> void {
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') return;
        grid[r][c] = '0';
        self(r + 1, c);
        self(r - 1, c);
        self(r, c + 1);
        self(r, c - 1);
    };
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '1'){
                count++;
                dfs(i, j);
            }
        }
    }
    return count;
}
int main(){
    vector<vector<int>> grid = {{'1', '0', '0', '1'},
                                {'1', '0', '1', '0'},
                                {'0', '1', '0', '1'},
                                {'1', '0', '1', '1'},
                                                    };
    int ans = numIsland(grid);                                                
    cout << ans << '\n';
}