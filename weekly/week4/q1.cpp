#include <bits/stdc++.h>
using namespace std;
vector<int> find(int n, vector<vector<int>>& edges){
    vector<bool> canGetTo(n, false);
    for(vector<int>& edge : edges){
        canGetTo[edge[1]] = true;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(!canGetTo[i]) ans.push_back(i);
    }
    return ans;

}
int main(){
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    const int n = 6;
    vector<int> ans = find(n, edges);
    for(int& x : ans){
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}