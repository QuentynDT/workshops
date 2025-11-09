#include <bits/stdc++.h>
using namespace std;
vector<int> twosum(vector<int>& v, int& target){
    unordered_map<int, int> position;
    for(int i = 0; i < v.size(); i++){
        int complement = target - v[i];
        if(position.count(complement)){
            return {position[complement], i};
        }
        position[v[i]] = i;
    }
    return {};
}
int main(){
    vector<int> v = {1, 2, 5, 6, 3, 8, 4, 9, 9, 0};
    int target = 17;
    vector<int> ans = twosum(v, target);
    if(!ans.empty()){
        cout << ans[0] << ' ' << ans[1] << '\n';
    }
    return 0;
}

// 5 -> 1

// not present : 5 -> 0