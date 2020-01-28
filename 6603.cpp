#include<iostream>
#include<vector>
using namespace std;

void DFS(int idx, int len, int k, int* set, bool* checked, vector<int> result){
	if(len==6){
		for(int i=0;i<result.size();i++) cout << result[i] << ' '; cout << '\n';
		return;
	}
	
	for(int i=idx;i<=k;i++){
		if(!checked[i]){
			checked[i]=true;
			result.push_back(set[i]);
			
			DFS(i, len+1, k, set, checked, result);
			
			checked[i]=false;
			result.pop_back();
		}
	}
}

int main()
{
	int k;
	
	while(1){
		cin >> k;
		if(k==0) break;
		
		int set[k+1]; bool checked[k+1]={0,}; vector<int> v;
		for(int i=1;i<=k;i++) cin >> set[i];
		
		DFS(1, 0, k, set, checked, v);
		cout << endl;
	}
	
	
	return 0;
}
