#include <bits/stdc++.h>
using namespace std;
int main(){
    int a = 4, b = 5, c = 6;
    int d = a & b;
    cout << d << '\n';
    int e = b | c;
    cout << e << '\n';
    int f = b ^ c;
    cout << f << '\n';
    int x = 46;
    for(int i = 0; i < 8; i++){
        if((x >> i) & 1){
            cout << "one in the " << i << "place\n";
        }
    }
    return 0;

}