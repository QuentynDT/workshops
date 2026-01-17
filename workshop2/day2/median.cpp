//Find the median of a stream of numbers

#include <bits/stdc++.h>
using namespace std;
class MainClass {
public:
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<>> right;
    void insert(int num){
        left.push(num);

        right.push(left.top());
        left.pop();
        
        if(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }
    }
    double findMedian(){
        if(left.size() > right.size()){
            return left.top();
        } else {
            return (left.top() + right.top()) / 2.0;
        }
    }
};
// x y z | a b c
int main() {
    MainClass m;
    m.insert(25);
    m.insert(24);
    cout << "Median is " << m.findMedian() << '\n';
    m.insert(15);
    m.insert(35);
    m.insert(100);
    cout << "Median is " << m.findMedian() << '\n';
}