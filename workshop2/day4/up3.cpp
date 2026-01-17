//Unique Paths 3
//0 means free space
//1 means start
//2 means end
//-1 means obstacle
#include <bits/stdc++.h>
using namespace std;



int up3(vector<vector<int>>& grid){
    const int m = grid.size(), n = grid[0].size();
    vector<int> begin, end;
    int count = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                begin = {i, j};
            } else if(grid[i][j] == 2){
                end = {i, j};
            } else if(grid[i][j] == 0){
                count++;
            }
        }
    }
    int ans = 0;
    auto dfs = [&](this auto self, int r, int c) -> void {
        //cout << r << ' ' << c << '\n';
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] < 0) return;
        if(r == end[0] && c == end[1]){
            if(count == 0){
                ans++;
            }
            return;
        }
        int temp = grid[r][c];
        grid[r][c] = -2;
        count--;
        self(r + 1, c);
        self(r - 1, c);
        self(r, c + 1);
        self(r, c - 1);
        count++;
        grid[r][c] = temp;
        return;
    };
    dfs(begin[0], begin[1]);
    return ans;
}
int main(){
    vector<vector<int>> grid = {{-1, 1, 0, 0},
                                {0, 0, -1, 0},
                                {0, 0, 2, 0},
                                {0, 0, 0, 0},
                                            };
    int ans = up3(grid);
    cout << ans << '\n';
}