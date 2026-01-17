//input graph, source = 1, dest = 5
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edgeToAdjList(int n, vector<vector<int>>& edges){
    vector<vector<int>> adj(n);
    for(vector<int>& edge : edges){
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
void print(vector<vector<int>>& m){
    for(const auto& v : m){
        for(const auto& x : v){
            cout << x << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool hasCycle(int n, vector<vector<int>>& adj){
    vector<bool> seen(n, false);
    auto dfs = [&](this auto self, int i, int p) -> bool {
        seen[i] = true;
        for(int neighbor : adj[i]){
            if(!seen[neighbor]){
                if(self(neighbor, i)) return true;
            } else if (neighbor != p) {
                return true;
            } 
        }
        return false;
    };
    for(int i = 0; i < n; i++){
        if(seen[i]) continue;
        if(dfs(i, -1)) return true;
    }
    return false;
}

int main(){
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}, {2, 3}, {5, 4}, {5, 1}};
    vector<vector<int>> adj = edgeToAdjList(n, edges);
    bool x = hasCycle(n, adj);
    if(x){
        cout << "We have cycle\n";
    } else {
        cout << "We don't\n";
    }
    return 0;
}