#include <bits/stdc++.h>
using namespace std;


//x -> 1110111001
//opt =1111111111
//x&o =1110111001
//5 -> 101
//4 -> 100
//6 -> 110
//5 AND 6 -> 100 = 4
//4 AND 6 -> 100
//4 AND 5 -> 100
int longestSubarray(vector<int>& nums) {
    const int n = nums.size();
    int mx = ranges::max(nums);
    int maxLength = 0, currLength = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == mx){
            currLength++;
        } else {
            maxLength = max(maxLength, currLength);
            currLength = 0;
        }
    }
    return max(currLength, maxLength);
}

int main(){
    vector<int> nums = {1,2,3,3, 0, 3, 3, 3, 3,2,2};
    int longest = longestSubarray(nums);
    cout << longest << '\n';
    return 0;
}