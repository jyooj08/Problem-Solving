#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void printPicture(int m, int n, vector<vector<int>> picture){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cout << picture[i][j] << ' ';
        cout << endl;
    }
}

int getArea(int m, int n, int x, int y, vector<vector<int>> &picture){
    queue<pair<int,int>> q;
    q.push({x, y});
    int val = picture[x][y];
    int size = 0;
    
    picture[x][y] = 0;
    while(!q.empty()){
        int a = q.front().first, b = q.front().second;
        q.pop();
        // cout << a << ", " << b << endl;
        size++;
        if(a+1<m && picture[a+1][b]==val) {q.push({a+1, b}); picture[a+1][b] = 0;}
        if(a-1>=0 && picture[a-1][b]==val) {q.push({a-1, b}); picture[a-1][b] = 0;}
        if(b+1<n && picture[a][b+1]==val) {q.push({a, b+1}); picture[a][b+1] = 0;}
        if(b-1>=0 && picture[a][b-1]==val) {q.push({a, b-1}); picture[a][b-1] = 0;}
    }
    
    return size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    bool finish = false;
    
    while(!finish){
        bool x = true;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(picture[i][j] > 0){
                    number_of_area++;
                    max_size_of_one_area = max(max_size_of_one_area, getArea(m,n,i,j,picture));
                    x = false;
                }
            }
        }
        finish = x;
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}