#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int len = progresses.size();
    vector<bool> finished(len, false);
    int start = 0;

    while(start < len){
        // add progress
        for(int i=0;i<len;i++){
            if(progresses[i] < 100) progresses[i] += speeds[i];
            if(progresses[i] >= 100) finished[i] = true;
        }

        //check start
        int count=0;
        while(start<len){
            if(progresses[start] >= 100){
                count++; start++;
            } else break;
        }
        if(count>0) answer.push_back(count);
    }
    
    return answer;
}