// s1 = "horse". s2 = "ros"
// horse -> hose -> rose -> ros

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
int minDistance(string s1, string s2){
    const int m = s1.size(), n = s2.size();
    //dp[i] ?????
    //dp[i][j] = min edit distance from s1 substr(0, i) and s2 substr(0, j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for(int i = 0; i <= m; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= n; j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            //i = 2, j = 1
            //hor, ro -> minDistance is hor -> or -> r -> ro = 3
            //hor, ros -> minDistance is hor -> or -> r -> ro -> ros = 4
            //hor, ror -> minDistance is hor -> ror -> 1
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            }
        }
    }
    return 9;
}
int main(){
    string s1 = "horsing", s2 = "ros";
    //distance between "horse" and "" = 5
    //distance between "orse" and "" = 4
    //distance between "ros" and "ros" ->    
    int ans = minDistance(s1, s2);
    cout << ans << '\n';
    return 0;
}