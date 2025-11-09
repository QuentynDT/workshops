#include <bits/stdc++.h>
using namespace std;
int duplicate(vector<int>& v){
    unordered_set<int> seen;
    for(int& x : v){
        if(seen.count(x)) return x;
        seen.insert(x);
    }
    return -1;
}
int main(){
    vector<int> v = {1, 2, 5, 6, 3, 800000, 4, 89, 9, 0};
    int x = duplicate(v);
    if(x != -1){
        cout << "There is a duplicate which is " << x << '\n';
    } else {
        cout << "No duplicate\n";
    }
    return 0;
}

// 5 -> 1

// not present : 5 -> 0