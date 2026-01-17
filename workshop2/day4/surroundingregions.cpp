
//Given a number of islands in an ocean. Assume that the ocean can flood any islands that
//are not connected to the edges of the grid. Flood all the valid islands and keep the rest.
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> grid = {{'1', '0', '0', '1'},
                                {'1', '0', '1', '0'},
                                {'0', '1', '0', '1'},
                                {'1', '0', '1', '1'},
                                                    };
    int ans = numIsland(grid);                                                
    cout << ans << '\n';
}