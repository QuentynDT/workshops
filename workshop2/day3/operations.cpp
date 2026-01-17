// int x = 10, y = 3
//op1 = x ++
//op2 = x --
//op3 = if(x is divisible by 11) x = x/11
//op3 = if(x is divisible by 5) x = x/5

//10 9 8 7 6 5 4 3 (7)
//10 -> 11 -> 1 -> 2 -> 3 (3)
//10 2 3 (2)

#include <bits/stdc++.h>
using namespace std;

int minOps(int x, int y){
    if(x <= y) return y - x;
    queue<int> q;
    q.push(x);
    unordered_set<int> visited;
    // 10 -> 9, 11, 2, 10/11 doesnt exist
    //9 -> 8, 10
    //11 -> 10, 12, 1
    for(int ans = 0; !q.empty(); ans++){
        for(int sz = q.size(); sz > 0; sz--){
            const int z = q.front();
            q.pop();
            if(z == y) return ans;
            if(visited.count(z)) continue;
            visited.insert(z);
            q.push(z - 1);
            q.push(z + 1);
            if(z % 11 == 0) q.push(z / 11);
            if(z % 5 == 0) q.push(z / 5);
        }
    }
    return -1;
}



int main(){
    int x = 76, y = 11;
    //76 75 15 14 13 12 11
    //76 77 7 8 9 10 11
    int z = minOps(x, y);
    cout << "Min ops is " << z << '\n';
    return 0;
}