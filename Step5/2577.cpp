#include<iostream>
using namespace std;

int main()
{
	int a, b, c, result;
	int histogram[10];
	for(int i=0;i<10;i++) histogram[i] = 0;
	
	cin >> a >> b >> c;
	result = a*b*c;
	
	while(result>0){
		histogram[result%10]++;
		result /= 10;
	}
	
	for(int i=0;i<10;i++) cout << histogram[i] << endl;
	return 0;
}
