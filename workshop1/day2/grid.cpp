//Leetcode 2017: Grid Game

//1 2 3 1
//4 5 6 5

//0 0 0 1 after first person traversal
//4 5 0 0

//0 0 0 1 after second person traversal 
//0 0 0 0

//note: only moving right or down.
//score1 = 17

//score2 = 9

//if the first person attempts to minimize the number of
//points scored by the second person, how many points will
//the SECOND person score?



#include <bits/stdc++.h>
using namespace std;

int score(vector<vector<int>>& grid){
    const int n = grid[0].size();
    int ans = INT_MAX;
    int sum0 = accumulate(grid[0].begin(), grid[0].end(), 0);
    int sum1 = 0;
    for(int i = 0; i < n; i++){
        sum0 -= grid[0][i];
        ans = min(ans, max(sum0, sum1));
        sum1 += grid[1][i];
    }
    return ans;

}
int main(){
    vector<vector<int>> grid = {{1, 2, 3, 4},
                                {5, 6, 7, 8}};
    int x = score(grid);
    cout << x << '\n';
    return 0;
}

