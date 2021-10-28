#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long start = 0;
    long long end = (long long)*max_element(times.begin(), times.end()) * n;
    long long mid;
    long long answer = end;
    
    while(start <= end){
        mid = (start + end)/2;
        long long sum = 0;
        for(int i=0;i<times.size();i++)
            sum += mid/times[i];
        
        if(sum < n) start = mid + 1;
        else {
            if(mid < answer) answer = mid;
            end = mid-1;
        }
    }
    
    
    return answer;
}