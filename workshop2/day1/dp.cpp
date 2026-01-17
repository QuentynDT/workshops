#include <bits/stdc++.h>
using namespace std;
int fib(int n){
    int oneback = 1;
    int twoback = 0;
    for(int i = 2; i <= n; i++){
        int curr = twoback + oneback;
        twoback = oneback;
        oneback = curr;
    }
    return oneback;
}
void fun(vector<vector<int>> matrix){
    
}
int main(){
    cout << "Find the nth Fibonacci number" << '\n';
    vector<vector<int>> matrix(5, vector<int>(5));
    const int m = matrix.size(), n = matrix[0].size();
    fun(matrix);
    int x = fib(1000);
    cout << "The number is " << x << '\n';
    return 0;
}