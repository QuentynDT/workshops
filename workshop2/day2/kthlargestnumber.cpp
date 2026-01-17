//Find the kth largest number of the list

#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<>> minHeap;
    vector<int> nums = {1, 5, 6, 3, 8, 9};
    int k = 6;
    for(int i = 0; i < nums.size(); i++){
        minHeap.push(nums[i]);
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    
    cout << minHeap.top() << ' ';
    cout << '\n';
    return 0;
}