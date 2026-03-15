#include <bits/stdc++.h>
using namespace std;
struct pair_hash {
    inline size_t operator()(const pair<int, int>& v) const {
        return v.first * 31 + v.second;
    }
};
int maxLength(vector<string>& arr){
    const int n = arr.size();
    vector<int> bit(26, 0);
    for(int i = 0; i < n; i++){
        bool duplicate = false;
        for(char& c : arr[i]){
            int x = c - 'a';
            if((bit[i] >> x) & 1){
                duplicate = true;
                break;
            }
            bit[i] |= (1 << x);
        }
        if(duplicate){
            bit[i] = -1;
        }
        //edcba
        //00011
        //01100
        // & -> 00000
    }
    unordered_map<pair<int, int>, int, pair_hash> memo;
    auto dfs = [&](this auto self, int i, int b) -> int {
        if(i == n) return 0;
        auto it = memo.find({i, b});
        if(it != memo.end()) return it->second;
        int result = self(i + 1, b);
        if(bit[i] != -1 && (b & bit[i]) == 0) {
            result = max(result, (int)arr[i].size() + self(i + 1, b | bit[i]));
        }
        memo[{i, b}] = result;
        return result;
    };
    return dfs(0, 0);
}
int main(){
    vector<string> arr = {"cha", "r", "act", "ers", "rra"};
    int ans = maxLength(arr);
    cout << ans << '\n';
    return 0;
}