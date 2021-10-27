#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int getIndex(vector<char> v, char ch){
    for(int i=0;i<8;i++)
        if(v[i] == ch) return i;
    return -1;
}

bool Ok(int a, int b, int dist, char ch){
    switch(ch){
        case '=':
            return abs(a-b) == dist;
        case '<':
            return abs(a-b) < dist;
        case '>':
            return abs(a-b) > dist;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    vector<char> v = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    int answer = 0;
    int size = data.size();
    
    do{
        bool ok = true;
        for(int i=0;i<size;i++){
            int dist =data[i][4] - '0' + 1;
            int i1= getIndex(v, data[i][0]);
            int i2 = getIndex(v, data[i][2]);
            // cout << i1 << ' ' << i2 <<endl;
            ok = Ok(i1, i2, dist, data[i][3]);
            if(!ok) break;
        }
        if(ok) answer++;
    }while(next_permutation(v.begin(), v.end()));
    
    return answer;
}