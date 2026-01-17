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

bool validPath(vector<bool>& seen, vector<vector<int>>& adj, int source, int dest){
    if(source == dest) return true;
    seen[source] = true;
    for(int& neighbor : adj[source]){
        if(seen[neighbor]) continue;
        if(validPath(seen, adj, neighbor, dest)) return true;
    }
    return false;
}

int main(){
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> adj = edgeToAdjList(n, edges);
    vector<bool> seen(n, false);
    bool x = validPath(seen, adj, 0, 4);
    if(x){
        cout << "True\n";
    } else {
        cout << "False\n";
    }
    return 0;
}