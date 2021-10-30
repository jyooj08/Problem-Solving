#include <string>
#include <vector>
#include <algorithm>

#include<iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int* arr = new int[n];
    fill_n(arr, n, 0);
    
    for(int i : lost){
        arr[i-1]--;
    }
    
    for(int i : reserve){
        arr[i-1]++;
    }
    
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            if(i-1>=0 && arr[i-1] > 0){
                arr[i-1]--; arr[i]++;
            } else if (i+1<n && arr[i+1] > 0){
                arr[i+1]--; arr[i]++;
            }
        }
    }
    
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i] >= 0) count++;
    }
    
    return count;
}