#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    /*
    30 31 32
    20 21 22
    10 11 12
    00 01 02
    */
    string pos[] = {"01", "30", "31", "32", "20", "21", "22", "10", "11", "12", "00", "02"};
    int left = 10, right = 11;
    for(int n: numbers){
        if(n==1 || n==4 || n==7){
            answer += "L"; left = n;
            continue;
        } else if (n==3 || n==6 || n==9){
            answer += "R"; right = n;
            continue;
        } else{
            int L = abs(pos[n][0]-pos[left][0]) + abs(pos[n][1]-pos[left][1]);
            int R = abs(pos[n][0]-pos[right][0]) + abs(pos[n][1]-pos[right][1]);
            
            if(L < R){
                answer += "L"; left = n;
            } else if (L > R){
                answer += "R"; right = n;
            } else if (hand == "left"){
                answer += "L"; left = n;
            } else if (hand == "right"){
                answer += "R"; right = n;
            }
        }
    }
    return answer;
}