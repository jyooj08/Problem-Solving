#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool visited[8+1] = {0,};
int numbers[8+1]; // ¼ö¿­ 


void search(vector<int> v, int k){
	bool push=true;
	for(int i=0;i<v.size();i++){
		if(k==v[i]){
			push=false; break;
		}
	}
	
	if(push) v.push_back(k);
	else return;
	
	if(v.size()==m){
		for(int i=0;i<m;i++) cout << v[i] << ' '; cout << '\n';
		return;
	}
	
	for(int i=1;i<=n;i++){
		search(v,i);
	}
}

void DFS(int length){
	if(length == m){
		for(int i=0;i<m;i++) cout << numbers[i] << ' '; cout << '\n';
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			visited[i]=true;
			numbers[length]=i;
			DFS(length+1);
			visited[i]=false;
		}
	}
}

int main()
{
	cin >> n >> m;
	
	/*
	vector<int> v;
	for(int i=1;i<=n;i++) {
		search(v, n, m, i);	
	}*/
	
	DFS(0);
	
	return 0;
}
