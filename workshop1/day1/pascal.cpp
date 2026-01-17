//Leetcode 118: Pascal's Triangle

//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1 

#include <bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>& ans){
    for(vector<int>& row : ans){
        for(int& val : row){
            cout << val << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void build_triangle(int n){
    vector<vector<int>> ans(n);
    ans[0] = {1};
    vector<int> row = {1};
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 1; j--){
            row[j] += row[j - 1];
        }
        row.push_back(1);
        ans[i] = row;
    }
    display(ans);
}

int main(){
    int n = 5;
    build_triangle(n);
    return 0;
}