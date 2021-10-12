#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int main()
{
	int t, n, pos;
	cin >> t;
	
	while(t--){
		cin >> n >> pos;
		
		int priority;
		int count=0;
		queue<pair<int, bool> > q;// priority, wanted document
		priority_queue<int> pq;
		
		for(int i=0;i<n;i++){
			cin >> priority;
			pq.push(priority);
			if(i==pos) q.push({priority, true});
			else q.push({priority, false});
		}
		
		while(1){
 		//cout << "max: "<<pq.top()<<endl;
			
			if(q.front().first != pq.top()){
				pair<int,bool> tmp = q.front();
				q.pop();
				q.push(tmp);
			} else{
				count++;
				if(q.front().second==true) break;
				q.pop(); pq.pop();
			}
		}
		
		cout << count << endl;
	}
	
	
	return 0;
}
