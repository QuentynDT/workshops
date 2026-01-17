#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {5, 6, 4, 3, 8};
    const int m = nums.size();
    vector<vector<int>> ans;
    vector<int> curr;

    auto subsets = [&](this auto self, int i) -> void {
        if(i == m){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        self(i + 1);
        curr.pop_back();
        self(i + 1);
    };

    subsets(0);
    for(const auto& v : ans){
        for(const auto& x : v){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}