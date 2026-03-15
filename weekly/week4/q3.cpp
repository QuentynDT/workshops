#include <bits/stdc++.h>
using namespace std;
long long minSec(int mountainHeight, vector<int>& workerTimes){
    const int n = workerTimes.size();
    //time = (n * (n + 1) / 2) * workerTimes[i];
    //y = (n * (n + 1) / 2)
    //2 * y = n ^ 2 + n
    //n ^ 2 + n - 2y = 0
    //n = (- 1 + (sqrt(1 + 8 * y))) / 2
    //in time t, how much of the mountain can worker i take down? 
    auto f = [&](long long t) -> int {
        int ans = 0;
        for(int i = 0; i < n; i++){
            int y = t / workerTimes[i];
            ans += (-1 + sqrt(1 + 8 * y))/2;
        }
        return ans;
    };
    int x = ranges::min(workerTimes);
    long long l = 0, r = (1LL * mountainHeight * (mountainHeight + 1)) / 2 * x;
    while(l < r){
        int m = l + (r - l)/2;
        int total = f(m);
        if(total < mountainHeight){
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;

}
int main(){
    int mountainHeight = 10;
    vector<int> workerTimes = {3, 2, 2, 4};
    long long ans = minSec(mountainHeight, workerTimes);
    cout << ans << '\n';
    return 0;
}