#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

void printQueue(queue<pair<int, int> > q){
    while(!q.empty()){
        cout << q.front().first << ',' << q.front().second << ' ';
        q.pop();
    }
    cout << endl;
}

bool higherPriority(queue<pair<int, int> > q, int priority){
    while(!q.empty()){
        if(priority < q.front().first) return true;
        q.pop();
    }
    return false;
}

int solution(vector<int> priorities, int location) {
    int idx = 0;
    queue<pair<int, int> > files; // priority, id
    for(int i=0;i<priorities.size();i++){
        files.push({priorities[i], i});
    }
    
    while(!files.empty()){
        pair<int, int> f = files.front();
        files.pop();
        if(higherPriority(files, f.first)){
            files.push(f);
            continue;
        }
        
        idx++;
        if(f.second == location) return idx;
    }
    
    return 0;
}