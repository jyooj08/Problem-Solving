#include <string>
#include <iostream>
#include <vector>
using namespace std;

int solution(string dartResult) {
    vector<int> answer;
    bool lastIsNum = false;
    for(char ch : dartResult){
        if('0' <= ch && ch <= '9'){
            if(lastIsNum){
                int n = answer.back(); answer.pop_back();
                answer.push_back(n*10 + ch-'0');
            } else answer.push_back(ch - '0');
            lastIsNum = true;
        } else if (ch == 'S'){
            lastIsNum = false;
        }else if (ch == 'D'){
            int n = answer.back();
            answer.pop_back();
            answer.push_back(n*n);
            lastIsNum = false;
        } else if (ch == 'T'){
            int n = answer.back();
            answer.pop_back();
            answer.push_back(n*n*n);
            lastIsNum = false;
        } else if (ch == '*'){
            if(answer.size() > 1){
                int n1 = answer.back(); answer.pop_back();
                int n2 = answer.back(); answer.pop_back();
                answer.push_back(2*n2); answer.push_back(2*n1);
            } else{
                int n1 = answer.back(); answer.pop_back(); answer.push_back(2*n1);
            }
            lastIsNum = false;
        } else if (ch == '#'){
            int n = answer.back();
            answer.pop_back();
            answer.push_back((-1)*n);
            lastIsNum = false;
        }
    }
    int n=0;
    for(int i : answer){
        n += i;
    }
    return n;
}