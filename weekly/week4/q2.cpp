#include <bits/stdc++.h>
using namespace std;
int swaps(vector<int>& row){
    int ans = 0;
    const int n = row.size();
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        pos[row[i]] = i;
    }
    for(int i = 0; i < n; i += 2){
        int first = row[i], second = row[i + 1];
        int partner = first ^ 1;
        //4 -> 100 ^ 001 = 101
        //5 -> 101 ^ 001 = 100
        // 0 ^ 1 = 1, 1 ^ 1 = 0
        if(second == partner) continue;
        ans++;
        int j = pos[partner];
        swap(row[j], row[i + 1]);
        pos[second] = j;
    }
    return ans;
}
int main(){
    
    vector<int> row = {0, 2, 1, 3};
    int ans = swaps(row);
    cout << ans << '\n';
    return 0;
}