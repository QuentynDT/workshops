//Leetcode 242: Valid Anagram
#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string& s1, string& s2){
    if(s1.size() != s2.size()) return false;
    vector<int> letters(26);
    const int n = s1.size();
    for(int i = 0; i < n; i++){
        letters[s1[i] - 'a']++;
        letters[s2[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(letters[i]){
            return false;
        }
    }
    return true;
    

}
int main(){
    string s1 = "silent";
    string s2 = "listen";
    if(isAnagram(s1, s2)){
        cout << s1 << " and " << s2 << " are anagrams\n";
    } else {
        cout << s1 << " and " << s2 << " are NOT anagrams\n";
    }
    return 0;
}