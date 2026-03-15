#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "abaab";
    string t = "ab";
    //s = aab, t = ba
    //s = aab?, t = b
    //ba
    bool possible = true;
    const int n = s.size();
    int l = 0, r = (n - 1) % 2;
    for(int i = 0; i < n; i++){
        char&c = s[i];
        if(c != '?'){
            if(c != s[l] && c != s[r]){
                possible = false;
                break;
            }
            if(c == s[l]) l ^= 1;
            else r ^= 1;
        } else {
            if(l == r){
                l ^= 1;
            } else {
                i++;
            }
        }
    }
    //l/r = 0, 'a'
    //l/r = 1, 'b'
    if(possible) cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}