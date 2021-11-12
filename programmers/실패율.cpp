#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double* eachStages = new double[N+1]; fill_n(eachStages, N+1, 0);
    double* totalStages = new double[N+1]; fill_n(totalStages, N+1, 0);
    double* rate = new double[N+1];
    
    for(int s : stages){
        eachStages[s-1]++;
    }
    totalStages[N] = eachStages[N];
    for(int i=N;i>0;i--){
        totalStages[i-1] = totalStages[i] + eachStages[i-1];
    }
    for(int i=0;i<=N;i++){
        if(totalStages[i]) rate[i] = eachStages[i] / totalStages[i];
        else rate[i] = 0;
    }
    for(int i=0;i<N;i++){
        double max = *max_element(rate, rate+N);
        for(int j=0;j<N;j++){
            if(max == rate[j]){
                answer.push_back(j+1);
                rate[j] = -1;
                break;
            }
        }
    }
    return answer;
}