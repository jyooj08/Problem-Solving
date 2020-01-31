#include<iostream>
#include<vector>
using namespace std;

int maxScore=0;
int* stair;
int n;

void up(int current, int score, int continuity, vector<int> trace){
	score += stair[current];
	trace.push_back(stair[current]);
	
	if(current==n) {
		//score += stair[current];
		maxScore = max(maxScore, score);
		
		//for(int i=0;i<trace.size();i++) cout << trace[i] << ' ';
		//cout << " score: "<<score<<endl;
		return;
	}
	
	if(current+1<=n && continuity<2) up(current+1, score, continuity+1, trace);
	if(current+2<=n) up(current+2, score, 1, trace);
}

int main()
{
	cin >> n;
	
	stair = new int[n+1];
	stair[0]=0;
	for(int i=1;i<=n;i++) cin >> stair[i];
	
	int score[n+1]={0,};
	score[1]=stair[1];
	score[2]=max(score[1], score[0])+stair[2];
	
	for(int i=3;i<=n;i++){
		score[i]=max(score[i-2]+stair[i], score[i-3]+stair[i-1]+stair[i]);
	}
	
	cout << score[n];
	return 0;
}
