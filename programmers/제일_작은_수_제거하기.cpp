#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = {-1};
    int minIdx = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] < arr[minIdx]) minIdx = i;
    }
    arr.erase(arr.begin()+minIdx);
    return arr.empty() ? answer : arr;
}