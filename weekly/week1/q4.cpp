#include <bits/stdc++.h>

using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> hs(n), ws(n);
    for(int i = 0; i < n; i++){
        cin >> hs[i] >> ws[i];
    }
    priority_queue<pair<int, int>> hq, wq;
    vector<bool> seen(n);
    for(int i = 0; i < n; i++){
        hq.push({hs[i], i});
        wq.push({ws[i], i});
    }
    bool done = false;
    while(!hq.empty() && !wq.empty()){
        auto &[p1, i1] = hq.top();
        auto &[p2, i2] = wq.top();
        while(seen[i1]){
            hq.pop();
            if(hq.empty()){
                done = true;
                break;
            }
            auto &[p1, i1] = hq.top();
        }
        while(seen[i2]){
            wq.pop();
            if(wq.empty()){
                done = true;
                break;
            }
            auto &[p1, i2] = wq.top();
        }
        if(done) break;
        // at this point, both top pieces are unseen.
        if(p1 == h){
            seen[i1] = true;
            w -= ws[i1];
            hs[i1] = 1;
            ws[i1] = w + 1;
            hq.pop();
        }
        else if(p2 == w){
            seen[i2] = true;
            h -= hs[i2];
            ws[i2] = 1;
            hs[i2] = h + 1;
            wq.pop();
        }
    }
    for(int i = 0; i < n; i++){
        cout << hs[i] << ' ' << ws[i] << '\n';
    }
    return 0;

}