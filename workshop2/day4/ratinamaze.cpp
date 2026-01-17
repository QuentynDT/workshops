//Rat in a Maze:
//DRDDRR
//DRRRDD
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> grid = {{'1', '0', '0', '1'},
                                {'1', '1', '1', '1'},
                                {'0', '1', '0', '1'},
                                {'1', '1', '1', '1'},
                                                    };
    vector<int> dx = {1, 0, 0, -1};   
    vector<int> dy = {0, -1, 1, 0};   
    vector<char> dirs = {'D', 'L', 'R', 'U'};
    int n = grid.size();
    vector<string> ans;
    string path = "";
    auto dfs = [&](this auto self, int r, int c) -> void {
        if(r == n - 1 && c == n - 1){
            ans.push_back(path);
        }
        if(r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == '0') return;
        grid[r][c] = '0';
        for(int i = 0; i < 4; i++){
            path.push_back(dirs[i]);
            self(r + dx[i], c + dy[i]);
            path.pop_back();
        }
        grid[r][c] = '1';
    };
    dfs(0, 0);
    for(string& s : ans){
        cout << s << '\n';
    }
}