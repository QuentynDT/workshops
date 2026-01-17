//Leetcode 125: Valid Palindrome
 
#include <bits/stdc++.h>
using namespace std;

bool pal(string& s){
    int l = 0;
    int r = s.size() - 1;
    while(l < r){
        while(l < r && !isalnum(s[l])) l++;
        while(l < r && !isalnum(s[r])) r--;
        if(l < r && s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int main(){
    string s = "abcd ??????? b dcb ???     a";
    if(pal(s)){
        cout << "It is palindrome\n";
    } else {
        cout << "it is not palindrome\n";
    }
    return 0;
}

