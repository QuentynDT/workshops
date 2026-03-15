#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "lmlm";
    //llmllm
    //**mllm
    //**m**m
    //******
    //
    const int n = s.size();
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(!st.empty() && s[i] == st.top()) st.pop();
        else st.push(s[i]);
    }
    cout << (st.empty() ? "Yes" : "No") << '\n';
    return 0;
}