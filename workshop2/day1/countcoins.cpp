// We have coins of different values, we want to form a 
//certain value using as few coins as possible
//if unable to, return -1

// {1, 2, 5, 10}, we need 9 -> 5 + 2 + 2
// {1, 4, 5} we need 8 -> 4 4

#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int sum){
    vector<int> dp(sum + 1, sum + 1);
    dp[0] = 0;
    //dp[i] -> How many coins needed to form a sum of i
    for(int coin : coins){
        for(int i = coin; i <= sum; i++){
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[sum] == sum + 1 ? -1 : dp[sum];

}
int main(){
    vector<int> coins = {1, 4, 5, 9, 10};
    //find 14, 
    int ans = minCoins(coins, 16);
    cout << ans << '\n';
    return 0;
}