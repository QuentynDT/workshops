//Leetcode 238: Product of Array Except Self
// 2 3 4 5 

// 60 40 30 24 

//no division allowed

#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

vector<int> product(vector<int> v){
    const int n = v.size();
    vector<int> ans(n);
    vector<int> before(n, 1);
    vector<int> after(n, 1);
    for(int i = 1; i < n; i++){
        before[i] = before[i - 1] * v[i - 1];
    }
    for(int i = n - 2; i >= 0; i--){
        after[i] = after[i + 1] * v[i + 1];
    }
    for(int i = 0; i < n; i++){
        ans[i] = before[i] * after[i];
    }
    return ans;
}

int main(){
    vector<int> v = {2, 3, 4, 5};
    vector<int> ans = product(v);
    print_vector(v);
    print_vector(ans);
    return 0;
}

