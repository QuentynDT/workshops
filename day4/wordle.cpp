#include <bits/stdc++.h>
using namespace std;

string wordle(string& guess, string& answer){
    if(guess.size() != answer.size()) return {};
    string result(5, 'b');
    vector<int> guessfreq(26), answerfreq(26);
    for(int i = 0; i < 5; i++){
        if(guess[i] == answer[i]){
            result[i] = 'g';
        } else {
            guessfreq[guess[i] - 'a']++;
            answerfreq[answer[i] - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++){
        if(guessfreq[i] != 0 && answerfreq[i] != 0){
            int minimum = min(guessfreq[i], answerfreq[i]);
            for(int j = 0; j < 5; j++){
                if(minimum == 0){
                    break;
                }
                if(guess[j] - 'a' == i){
                    result[j] = 'y';
                    minimum--;
                }
            }
        }
    }
    return result;
}

//O(n)
int main(){
    string guess = "stake";
    string answer = "tract";
    string result = wordle(guess, answer);
    cout << result << '\n';
    return 0;
}
