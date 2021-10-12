#include<iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n;
	
	int arr[10001] = {0,};
	
	while(n--){
		scanf("%d",&k);
		arr[k]++;
	}
	
	for(int i=1;i<=10000;i++){
		for(int j=0;j<arr[i];j++){
			printf("%d\n",i);
		}
	}
	
	return 0;
}
