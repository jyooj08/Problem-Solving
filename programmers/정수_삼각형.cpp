#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int len = triangle.size();
    vector<int> dp = triangle[len-1];
    
    for(int i=len-2;i>=0;i--){
        vector<int> result;
        for(int j=0;j<=i;j++){
            result.push_back(max(triangle[i][j]+dp[j], triangle[i][j]+dp[j+1]));
        }
        
        dp = result;
    }
    
    return dp[0];
}