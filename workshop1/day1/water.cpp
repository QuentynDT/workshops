//Leetcode 11: Container With Most Water
#include <bits/stdc++.h>
using namespace std;

int maxcapacity(vector<int>& v){
    int solution = 0;
    int l = 0, r = v.size() - 1;
    while(l < r){
        int minHeight = min(v[l], v[r]);
        int volume = minHeight * (r - l);
        solution = max(solution, volume);
        if(v[l] < v[r]){
            l++;
        } else {
            r--;
        }
    }
    return solution;
}
int main(){
    vector<int> v = {5, 3, 1, 4, 2};
    int cap = maxcapacity(v);
    cout << cap << " is the max capacity\n";
    return 0;
}

