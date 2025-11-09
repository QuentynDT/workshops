#include <bits/stdc++.h>
using namespace std;

bool subZero(vector<int>& v){
    const int n = v.size();
    unordered_set<int> seen;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        if(seen.count(sum)) return true;
        seen.insert(sum);
    }
    return false;
}

//O(n)
int main(){
    vector<int> v{1000000, 2, 4, 5, 5, -4, 1, 2};
    bool x = subZero(v);
    if(x){
        cout << "it does\n";
    } else {
        cout << "it doesnt\n";
    }
    return 0;
}
