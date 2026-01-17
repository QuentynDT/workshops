//Leetcode 78: Subsets
// 1 2 3

//_, 1, 2, 3, 1 2, 2 3, 1 3, 1 2 3

//000, 100, 010, 001, 110, 011, 101, 111


//1 2

// _, 1, 2, 1 2
#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int>& v){
    int n = v.size();
    for(int& x : v){
        cout << x << ' ';
    }
    cout << '\n';
}
vector<vector<int>> subsets(vector<int>& v){
    const int n = v.size();
    int total = 1 << n;
    int idx = 0;
    vector<vector<int>> ans(total);
    for(int i = 0; i < total; i++){
        //0 0 1 vs 1 0 0
        vector<int> subset;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                subset.push_back(v[j]);
            }
        }
        ans[idx++] = subset;
    }
    return ans;
}
int main(){         
    vector<int> v = {4, 5, 6};
    //               0  1  2
    vector<vector<int>> ans = subsets(v);
    for(vector<int>& y : ans){
        print_vector(y);
    }
    return 0;

}