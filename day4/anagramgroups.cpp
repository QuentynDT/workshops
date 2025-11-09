#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> anagramGroups(vector<string>& strs){
    vector<vector<string>> ans;
    map<string, vector<string>> groups;
    for(string& s : strs){
        string temp = s;
        sort(temp.begin(), temp.end());
        groups[temp].push_back(s);
    }
    for(const auto& [s, anagrams] : groups){
        ans.push_back(anagrams);
    }
    return ans;
}
int main(){
    vector<string> strs = {"eat", "tea", "listen", "ball", "silent", "aaab", "baaa"};
    vector<vector<string>> groups = anagramGroups(strs);
    for(vector<string>& st : groups){
        for(string& s : st){
            cout << s << ' ';
        }
        cout << '\n';
    }
    return 0;
}