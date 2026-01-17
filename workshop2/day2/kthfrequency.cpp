//Find the kth most frequent number of the list

#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    vector<int> nums = {1, 1, 3, 3, 3, 5, 6, 8, 8, 8, 8, 9, 9};
    int k = 4;
    unordered_map<int, int> freq;
    for(int& x : nums){
        freq[x]++;
    }
    for(const auto& [x, f] : freq){
        minHeap.push({f, x});
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    
    cout << minHeap.top().second << ' ' << minHeap.top().first << ' ';
    cout << '\n';
    return 0;
}