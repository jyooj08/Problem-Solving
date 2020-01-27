#include<iostream>
#include<cmath>
using namespace std;

int n, count=0;
//bool** board;
int* row;

bool isPossible(int k){
	for(int i=0;i<k;i++){
		if(row[i]==row[k] || abs(row[i]-row[k])==(k-i)) return false;
	}
	return true;
}

void DFS(int k){
	if(k==n){
		count++;
		return;
	}
	
	for(int i=0;i<n;i++){
		row[k]=i;
		if(isPossible(k)){
			DFS(k+1);
		}
	}
}

int main()
{
	//init
	cin >> n;
	row = new int[n];	
	DFS(0);
	
	cout << count;
	
	return 0;
}
