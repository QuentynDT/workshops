//input graph, source = 1, dest = 5


#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edgeToAdjList(int n, vector<vector<int>>& edges){
    vector<vector<int>> adj(n);
    for(vector<int>& edge : edges){
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
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
vector<int> topSort(int n, vector<vector<int>>& adj){
    vector<int> inDegree(n, 0);
    for(int i = 0; i < n; i++){
        for(int neighbor : adj[i]){
            inDegree[neighbor]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    vector<int> ans;
    //0 -> 6 -> 1 -> 7 -> 5 -> 4 -> 2 -> 3
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(int neighbor : adj[curr]){
            inDegree[neighbor]--;
            if(inDegree[neighbor] == 0) q.push(neighbor);
        }
    }
    if(ans.size() != n) return {};
    return ans;
}
int main(){
    int n = 8;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 5}, {5, 4}, {4, 2}, {2, 3}, {6, 7}};
    vector<vector<int>> adj = edgeToAdjList(n, edges);
    vector<int> sorted = topSort(n, adj);
    if(sorted.empty()){
        cout << "We have a cycle\n";
    } else {
        for(int i = 0; i < n; i++){
            cout << sorted[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}