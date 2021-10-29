#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<string> op_priority = {"*", "+", "-"};
    vector<string> exp, exp2;
    
    string n = "";
    for(int i=0;i<expression.size();i++){
        if('0'<=expression[i] && expression[i] <= '9') n += expression[i];
        else{
            exp.push_back(n); n = "";
            string s = ""; s += expression[i]; exp.push_back(s);
        }
    } exp.push_back(n);
    
    do{
        // for(int i=0;i<op_priority.size();i++) cout << op_priority[i] << ' ';cout<<endl;
        exp2 = {exp.begin(), exp.end()};
        long long result;
        for(int i=0;i<3;i++){
            for(int j=0;j<exp2.size();j++){
                if(exp2[j] == op_priority[i]){
                    if(exp2[j] == "*") result = stoll(exp2[j-1]) * stoll(exp2[j+1]);
                    else if(exp2[j] == "+") result = stoll(exp2[j-1]) + stoll(exp2[j+1]);
                    else if(exp2[j] == "-") result = stoll(exp2[j-1]) - stoll(exp2[j+1]);

                    exp2.erase(exp2.begin()+j-1, exp2.begin()+j+2);
                    exp2.insert(exp2.begin()+j-1, to_string(result));
                    // for(int k=0;k<exp2.size();k++) cout << exp2[k] << ' ';cout<<endl;
                    j=0;
                }
            }
        }
    if(abs(result) > answer) answer = abs(result);

    }while(next_permutation(op_priority.begin(), op_priority.end()));
    return answer;
}