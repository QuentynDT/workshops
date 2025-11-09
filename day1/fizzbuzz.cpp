#include <bits/stdc++.h>
using namespace std;
//You are given a number as input aka 15. You must print the fizzbuzz value of each number from 1 to 15.
//The fizzbuzz string of a number is "fizz" if the number is divisible by 3.
int main(){
    int size;
    cout << "Enter size\n";
    cin >> size;
    vector<string> ans;
    for(int i = 1; i <= size; i++){
        string s = "";
        if(i % 3 == 0){
            s += "fizz";
        }
        if(i % 5 == 0){
            s += "buzz";
        }
        if(i % 5 != 0 && i % 3 != 0){
            s += to_string(i);
        }
        ans.push_back(s);
    }
    for(string &temp : ans){
        cout << temp << '\n';
    }
    return 0;
}