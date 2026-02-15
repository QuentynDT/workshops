#include <bits/stdc++.h>
using namespace std;
// 0 0 0 0 

// -4 -4 | 4 4

// 1 1 | -1 -1

//4 4 4 | -4 -5

//0 0 0 0 0

//5 5 5 5 5
bool isValid(vector<int>& arr) {
    int divSize = 1;
    int front = arr[0];
    int back;
    
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] != arr[i - 1]){
            back = arr[i];
            divSize++;
            if(divSize > 2 || front + back != 0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> nums = {3, 3, -3, 3};
    if(isValid(nums)){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}