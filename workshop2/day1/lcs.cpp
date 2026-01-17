#include <bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>& dp){
    for(const auto& v : dp){
        for(const auto& x : v){
            cout << x << ' ';
        }
        cout << '\n';
    }
}
int lcs(string s1, string s2){
    const int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            //dp[i][j] is the lcs between s1 substr 0 to i and s2 substr 0 to j
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    display(dp);
    return dp[m][n];
    return 0;
}
int main(){
    string s1 = "horsing", s2 = "ros";
    // "btx" vs "ca" -> 0
    // "bt" vs "cat" -> 1
    // "btx" vs "cat" -> 1

    cout << lcs(s1, s2) << '\n';
    return 0;
}