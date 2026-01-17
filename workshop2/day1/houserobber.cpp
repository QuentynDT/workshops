//You are robbing a street of houses. You cannot rob two adjacent 
//houses without setting off an alarm. Maximize your theft.

#include <bits/stdc++.h>
using namespace std;
int rob(vector<int>& houses){
    int n = houses.size();
    if(n == 0) return 0;
    if(n == 1) return houses[0];
    vector<int> dp(n);
    //dp[i] is the max profit gained by the first i houses.
    dp[0] = houses[0];
    dp[1] = max(houses[0], houses[1]);
    for(int i = 2; i < n; i++){
        dp[i] = max(houses[i] + dp[i - 2], dp[i - 1]);
    } 
    return dp[n - 1];

}
int main(){
    vector<int> houses = {4, 6, 5, 3, 7, 5};
    int mx = rob(houses);
    cout << mx << '\n';
    return 0;
}