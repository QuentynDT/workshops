#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
    vector<vector<int>> ans;
    ranges::sort(people, ranges::less{}, [](const vector<int>& person) {
        return pair<int, int>{-person[0], person[1]};
    });
    for(const vector<int>& person : people){
        ans.insert(ans.begin() + person[1], person);
    }
    return ans;

}
void d(vector<vector<int>>& m){
    for(const vector<int>& v : m){
        for(const int& x : v){
            cout << x << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
//{7, 0}, {7, 1}, {6, 1}, {5, 0}, {5, 2}, {4, 4}
int main(){
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    //vector<vector<int>> ans = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
    vector<vector<int>> ans = reconstructQueue(people);
    d(people);
    d(ans);
    return 0;
}