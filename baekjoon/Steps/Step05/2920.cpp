#include<iostream>
using namespace std;

int main(){
	int arr[8];
	for(int i=0;i<8;i++) cin >> arr[i];
	
	//ascending
	bool ascending=true, descending=true;
	for(int i=0;i<7;i++){
		if(arr[i]<arr[i+1]) descending=false;
		else if (arr[i]>arr[i+1]) ascending = false;
	}
	
	if(!ascending && !descending) cout << "mixed";
	else if (ascending && !descending) cout << "ascending";
	else if (!ascending && descending) cout << "descending";
	return 0;
}
