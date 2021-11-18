#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b){
    // int len = min(a.size(), b.size());
    // for(int i=0;i<len;i++){
    //     if(a[i] != b[i]) return a[i] > b[i];
    // }
    
//     if(a.size() < b.size() && a[len-1] != b[len]) return a[len-1] > b[len];
//     if(a.size() > b.size() && a[len] != b[len-1]) return a[len] > b[len-1];
    
//     return false;
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    int len = numbers.size();
    vector<string> nums;
    for(int i=0;i<len;i++) nums.push_back(to_string(numbers[i]));
    
    sort(nums.begin(), nums.end(), cmp);
    
    // for(int i=0;i<len;i++) cout << nums[i] << ' ';cout<<endl;
    
    for(int i=0;i<len;i++){
        answer += nums[i];
    }
    
    if(answer[0] == '0') answer="0";
    
    return answer;
}