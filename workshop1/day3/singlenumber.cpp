//Leetcode 136: Single Number
#include <bits/stdc++.h>
using namespace std;

int singlenumber(vector<int>& v){
    int ans = 0;
    for(int& x : v){
        ans ^= x;
    }
    return ans;
}
int main(){
    vector<int> v = {5, 4, 1, 2, 3, 4, 5, 2, 1};
    cout << singlenumber(v) << '\n';
    return 0;

}