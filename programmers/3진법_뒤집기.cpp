#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int solution(int n) {
    int answer = 0;
    string num = "";
    while(n > 0){
        num += to_string(n%3);
        n /= 3;
    }
    // num += to_string(n);
    
    int len = num.length();
    int x = 1;
    for(int i=len-1;i>=0;i--){
        answer += x * (num[i] - 48);
        x *= 3;
    }
    return answer;
}