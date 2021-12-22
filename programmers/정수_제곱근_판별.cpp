#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long a = sqrt(n);
    if(a*a == n){
        return (a+1)*(a+1);
    } else{
        return -1;
    }
}