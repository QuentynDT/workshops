//Leetcode 1004: Max Consecutive Ones III

//1 0 1 0 1 0 1 0 0 0 0 1 1 1
//k = 2


#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int>& v, int k){
    int ans = 0;
    int l = 0, r = 0;
    const int n = v.size();
    while(r < n){
        if(v[r] == 0){
            k--;
        }
        while(k < 0){
            if(v[l] == 0){
                k++;
            }
            l++;
        }
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}
int main(){
    vector<int> v{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1};
    int k = 3;
    int x = maxConsecutiveOnes(v, k);
    cout << "Number of consecutive ones: " << x << '\n';
    return 0;
}

