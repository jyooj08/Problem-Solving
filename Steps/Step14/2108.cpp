#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	double sum=0;
	cin >> n;
	
	// counting sort
	int histogram[8001] = {0,}; // index - 4000 is number
	int arr[n];
	for(int i=0;i<n;i++){
		cin >> arr[i];
		sum += arr[i];
		histogram[arr[i]+4000]++;
	}
	
	//1
	cout << (int)round(sum/(double)n)<<endl; // 앞에 int 붙여줘야함 
	
	//2
	sort(arr, arr+n);
	cout << arr[n/2] << endl;
	
	//3
	int max=0; bool second=false;
	for(int i=1;i<=8000;i++){
		if(histogram[i] > histogram[max]) {
			second=false;
			max=i;
		} else if (histogram[i]==histogram[max] && !second){
			second=true;
			max=i;
		}
	}
	cout << max-4000 << endl;
	
	//4
	cout << arr[n-1] - arr[0] <<endl;
	return 0;
}
