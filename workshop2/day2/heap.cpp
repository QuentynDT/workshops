#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int, vector<int>> maxHeap;
    vector<int> nums = {1, 5, 6, 3, 8, 9};
    int k = 3;
    for(int i = 0; i < nums.size(); i++){
        maxHeap.push(nums[i]);
        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }
    while(!maxHeap.empty()){
        cout << maxHeap.top() << ' ';
        maxHeap.pop();
    }
    cout << '\n';
    return 0;
}