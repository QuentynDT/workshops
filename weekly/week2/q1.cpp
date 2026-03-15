#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& adj, const int n){
    vector<int> color(n, 0); // 0 -> uncolored, 1->red, -1 ->blue
    auto dfs = [&](this auto self, int u, int c) -> bool {
        color[u] = c;
        for(int v : adj[u]){
            if(color[v] == c || (color[v] == 0 && !self(v, -c))) return false;
        }
        return true;
    };
    for(int i = 0; i < n; i++){
        if(color[i] == 0 && !dfs(i, 1)){
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> edges = {{1, 2}, {3, 1}, {2, 3}, {1, 0}};
    const int n = 4;
    vector<vector<int>> adj(n);
    for(auto& edge : edges){
        const int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = isBipartite(adj, n);
    if(ans){
        cout << "it is\n";
    } else {
        cout << "it isnt\n";
    }
    return 0;
}