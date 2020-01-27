#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool visited[8+1] = {0,};
int numbers[8+1]; // ¼ö¿­ 

void search(vector<int> v, int k){
	if(v.size()==0 || k > v.back()) v.push_back(k);
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
		if(!visited[i] && (length==0 || (length>0 && numbers[length-1]<i))){
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
	}
	*/
	
	DFS(0);
	
	return 0;
}
