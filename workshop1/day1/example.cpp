#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<int> v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main(){
    vector<int> v = {1, 2, 3};
    cout << v.max_size() << '\n';
    return 0;
}
