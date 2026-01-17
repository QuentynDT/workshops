//Leetcode 53: Maximum Subarray
#include <bits/stdc++.h>
using namespace std;

// -1 1 -2 3 4 -5 3 6 -2
int maxsubarraysum(vector<int>& v){
    const int n = v.size();
    int solution = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        solution = max(solution, sum);
        if(sum < 0) sum = 0;
    }
    return solution;
}
int main(){
    vector<int> v{-1, 1, -2, 3, 4, -5, 3, 6, -2};
    int sum = maxsubarraysum(v);
    cout << "Max subarray sum is " << sum << '\n';
    return 0;
}


//O(n) = Kadane's algorithm