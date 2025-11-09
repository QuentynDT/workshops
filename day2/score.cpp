// 1 0 0 1 0 0 | 1 1 0 1 0

#include <bits/stdc++.h>
using namespace std;

int score(vector<int>& v){
    int ans = 0;
    int zeroes = 0;
    int ones = 0;
    const int n = v.size();
    for(int i = 0; i < n; i++){
        if(v[i] == 1){
            ones++;
        }
    }
    for(int i = 0; i < n; i++){
        if(v[i] == 1){
            ones--;
        }
        else {
            zeroes++;
        }
        ans = max(ans, zeroes + ones);
    }
    return ans;
}


int main(){
    vector<int> v = {1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0};
    int x = score(v);
    cout << x << '\n';
    return 0;
}

