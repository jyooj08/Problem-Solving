#include <iostream>
#include <cmath>
using namespace std;

int GCD(int a, int b){
    if(b == 0){
        return a;
    }else{
        return GCD(b, a%b);
    }
}


long long solution(int w,int h) {
    int gcd = GCD(w, h);    
    return (long long)w * (long long)h - (w + h - gcd);
}