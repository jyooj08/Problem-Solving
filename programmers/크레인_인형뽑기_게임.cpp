#include <string>
#include <vector>
#include <stack>

#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size();
    stack<int> basket;
    int count = 0;
    
    for(int j: moves){
        j--;
        int i = 0;
        while(board[i][j] == 0 && i < n) i++;
        if(i >= n) continue;
        
        int val = board.at(i).at(j);
        board[i][j]=0;
        
        if(basket.empty() || basket.top() != val){
            basket.push(val);
        } else {
            basket.pop();
            count += 2;
        }
    }
    
    return count;
}