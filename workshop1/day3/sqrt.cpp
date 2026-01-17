//Leetcode 69: Sqrt(x)
#include <bits/stdc++.h>
using namespace std;

int mysqrt(int x){
    int l = 1;
    int r = x;
    while(l < r){
        int m = l + (r - l)/2;
        if(m > x / m){
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l - 1;
}

int main(){
    int x = -2;
    int y = mysqrt(x);
    cout << "Square root of " << x << " is " << y << '\n';
    int p = 50;
    int q = mysqrt(p);
    cout << "Square root of " << p << " is " << q << '\n';
    return 0;

}