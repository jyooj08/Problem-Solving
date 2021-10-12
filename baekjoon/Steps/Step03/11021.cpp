#include<iostream>
using namespace std;

int main(){
	int testcase, a, b;
	cin >> testcase;
	
	for(int i=0;i<testcase;i++){
		cin >> a >> b;
		cout << "Case #" << i+1 << ": " << a+b << endl;
	}
	return 0;
}
