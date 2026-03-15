#include <bits/stdc++.h>
using namespace std;
int minCapability(vector<int>& nums, int k){
    const int n = nums.size();
    auto f = [&](int x) -> bool {
        int count = 0, j = n;
        for(int i = 0; i < n; i++){
            if(nums[i] > x || i == j + 1) continue;
            count++;
            j = i;
        }
        return count >= k;
    };
    int left = 0, right = ranges::max(nums);
    while(left < right){
        int mid = (left + right) / 2;
        if(f(mid)){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    vector<int> nums = {2, 7, 9, 3, 1};

    int k = 2;
    int x = minCapability(nums, k);
    cout << "ans: " << x << '\n';
    return 0;
}