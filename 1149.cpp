#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int total[n+1][3];
	int cost[n+1][3];
	
	cost[0][0]=0; cost[0][1]=0; cost[0][2]=0;
	total[0][0]=0; total[0][1]=0; total[0][2]=0;
	for(int i=1;i<=n;i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	
	for(int i=1;i<=n;i++){
		total[i][0] = min(total[i-1][1], total[i-1][2]) + cost[i][0];
		total[i][1] = min(total[i-1][0], total[i-1][2]) + cost[i][1];
		total[i][2] = min(total[i-1][0], total[i-1][1]) + cost[i][2];
	}
	
	cout << min(total[n][0], min(total[n][1], total[n][2]));
	return 0;
}
