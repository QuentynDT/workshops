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

vector<int> shortestPath(int n, vector<vector<int>>& adj, int start){
    vector<int> dist(n, -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int neighbor : adj[curr]){
            if((dist[neighbor] == -1)){
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist;
}

int main(){
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 5}, {5, 4}, {4, 1}};
    vector<vector<int>> adj = edgeToAdjList(n, edges);
    vector<int> dists = shortestPath(n, adj, 0);
    for(int i = 0; i < n; i++){
        cout << "Distance from 0 to " << i << " is " << dists[i] << '\n';
    }
    return 0;
}