#include <bits/stdc++.h>
using namespace std; 
struct Fraction {
    long long num, den;
    void simplify() {
        long long mygcd = gcd(num, den);
        num /= mygcd, den /= mygcd;
    }
    bool operator<(const Fraction& other) const {
        if(num != other.num) return num < other.num;
        return den < other.den;
    }
    bool operator==(long long k) const {
        return den == 1 && num == k;
    }
};
int countSequences(vector<int>& nums, long long k){
    const int n = nums.size();
    map<pair<int, Fraction>, int> memo;
    auto dfs = [&](this auto self, int i, Fraction x) -> int {
        if(i == n) return x == k;
        if(memo.count({i, x})) return memo[{i, x}];
        Fraction mul = {x.num * nums[i], x.den};
        mul.simplify();
        Fraction div = {x.num, x.den * nums[i]};
        div.simplify();
        memo[{i, x}] = self(i + 1, mul) + self(i + 1, div) + self(i + 1, x);
        return memo[{i, x}];
    };
    return dfs(0, {1, 1});
}
int main(){
    vector<int> nums = {2, 3, 2};
    long long k = 6;
    int ans = countSequences(nums, k);
    cout << "ans is " << ans << '\n';
    return 0;
}