//Leetcode 704. Binary Search
#include <bits/stdc++.h>
using namespace std;

int binsearch(vector<int>& v, int target){
    const int n = v.size();
    int l = 0, r = n - 1;
    while(l <= r){
        int m = l + (r - l)/2;
        if(v[m] == target){
            return m;
        } else if (v[m] < target){
            l = m + 1;
        } else if (v[m] > target) {
            r = m - 1;
        }
    }
    return -1;

    //time complexity O(log(n));
}

int main(){
    vector<int> v = {10, 13, 19, 24, 32, 39, 57, 67, 99};
    int target1 = 25;
    int target2 = 67;
    int result1 = binsearch(v, target1);
    int result2 = binsearch(v, target2);
    if(result1 == -1){
        cout << target1 << " not found in vector\n";
    } else {
        cout << target1 << " found in vector at position " << result1 << '\n';
    }
    if(result2 == -1){
        cout << target2 << " not found in vector\n";
    } else {
        cout << target2 << " found in vector at position " << result2 << '\n';
    }
    return 0;

}