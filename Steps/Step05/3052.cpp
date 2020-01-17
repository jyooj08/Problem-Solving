#include<iostream>
using namespace std;

int main()
{
	int n, frequency=0; 
	int histogram[42];
	for(int i=0;i<42;i++) histogram[i]=0;
	
	for(int i=0;i<10;i++){
		cin >> n;
		histogram[n%42]++;
	}
	
	for(int i=0;i<42;i++){
		if(histogram[i] > 0) frequency++;
	}
	
	cout << frequency;
	return 0;
}
