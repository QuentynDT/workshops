#include <bits/stdc++.h>
using namespace std;
int integerReplacement(int n){
    // n = n + 1
    // n = n - 1
    //7 - 8 - 4 - 2 - 1
    //5 - 6 - 3 - 2 - 1
    //5 - 4 - 2 - 1

    //101
    //110
    //100
    //1000
    //001

    //00, 01, 10, 11
    //00 divide
    //01 -> 00
    //10 divide
    //011 -> 100 
    //3 4 2 1
    //3 2 1
    int ans = 0;
    while(n > 3){
        if(n % 2 == 0){
            n  >>= 1;
        }
        else if((n & 0x3) == 3){
            n++;
        } else {
            n--;
        }
        ans++;
    }
    return n - 1 + ans;

}

int main(){
    int n = 15;
    int ans = integerReplacement(n);
    cout << "ans: " << ans << '\n';
    return 0;
}