#include<iostream>
using namespace std;

int main()
{
	int white_count=0;
	char tmp;
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin >> tmp;
			if((i+j)%2==0 && tmp=='F') white_count++;
		}
	}
	
	cout << white_count;
	
	return 0;
}
