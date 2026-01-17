#include <bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int, int> mymap;
    vector<int> myvec(100001);
    vec[1] = 5;
    vec[2] = 8;
    vec[100000] = 5;
    // mymap[1] = 5;
    // mymap[2] = 8;
    // cout << mymap.size() << '\n';
    // for(const auto& [x, y] : mymap){
    //     cout << x << ' ' << y << '\n';
    // }
    unordered_set<int> myset;
    vector<bool> myvec2(10);
    myvec2[5] = true;
    myvec2[6] = true;
    myset.insert(5);
    myset.insert(6);
    for(const auto& x : myset){
        cout << x << '\n';
    }
    return 0;
}

//vector            : ordered   limited in size  O(1);
//ordered map/set   : ordered    unlimited      O(log (n)) = slow
//unordered map/set : unordered  unlimited      O(1);