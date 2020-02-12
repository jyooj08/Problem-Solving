#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int n;
int num[11];
int op[4];
long minval=LONG_MAX; 
long maxval=LONG_MIN;

void DFS(int i, long value){	
	//printf("%d번째 숫자 %d, current value=%d, min=%d, max=%d\n", i, num[i], value, minval, maxval);
	if(i==n-1) {
		if(value < minval) minval=value;
		if(value > maxval) maxval=value;
		return;
	}
	
	if(op[0]>0){
		op[0]--;
		DFS(i+1, value+num[i+1]);
		op[0]++;
	}
	if(op[1]>0){
		op[1]--;
		DFS(i+1, value-num[i+1]);
		op[1]++;
	}
	if(op[2]>0){
		op[2]--;
		DFS(i+1, value*num[i+1]);
		op[2]++;
	}
	if(op[3]>0){
		op[3]--;
		DFS(i+1, value/num[i+1]);
		op[3]++;
	}
}

int main()
{
	int k;
	cin >> n;
	for(int i=0;i<n;i++) cin >> num[i];
	for(int i=0;i<4;i++) cin >> op[i];
	
	//for(int i=0;i<n;i++) cout << num[i] << ' ';cout <<endl;
	DFS(0, num[0]);
	
	cout << maxval << endl << minval;
	
	return 0;
}
