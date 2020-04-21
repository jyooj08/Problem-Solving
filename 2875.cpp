#include<iostream>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	
	int max_team = min(n/2, m);
	//cout << "max_team: "<<max_team<<endl;
	
	int remain_girl = n - max_team*2;
	int remain_boy = m - max_team;
	//cout << "remain girl : "<<remain_girl <<", boy: "<<remain_boy<<endl;
	
	k = k - remain_girl - remain_boy;
	//cout << "fist k: "<<k<<endl;
	while(k > 0){
		k -= 3;
		max_team -= 1;
	}
	cout << max_team<<endl;
	
	return 0;
}
