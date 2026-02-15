#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n){
        parent.resize(n + 1);
        // for(int i = 0; i < n; i++){
        //     parent[i] = i;
        // } does the same as iota
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u){
        if(parent[u] == u) return u;
        parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u, int v){
        int p_u = find(u);
        int p_v = find(v);
        if(p_u != p_v){
            parent[p_u] = p_v;
            return true;
        }
        return false;
    }
};
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        DSU dsu(n);
        for(auto& edge : edges){
            if(!dsu.unite(edge[0], edge[1])){
                return edge;
            }
        }
        return {};
}
int main(){
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 4}, {3, 4}};
    vector<int> ans = findRedundantConnection(edges);
    cout << ans[0] << ' ' << ans[1] << '\n';
    return 0;
}