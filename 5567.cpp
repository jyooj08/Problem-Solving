#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;
	vector<int>* friends;

	cin >> n >> m;
	friends = new vector<int>[n+1];

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	vector<int> guest = friends[1]; guest.push_back(1);
	for(int i=0;i<friends[1].size();i++){
		int f = friends[1][i];
		for(int j=0;j<friends[f].size();j++){
			bool alreadyGuest=false;
			for(int k=0;k<guest.size();k++){
				if(friends[f][j] == guest[k]){
					alreadyGuest = true; break;
				}
			}
			
			if(!alreadyGuest) guest.push_back(friends[f][j]);
		}
	}
	
	cout << guest.size() - 1;

	return 0;
}
