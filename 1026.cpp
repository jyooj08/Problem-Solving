#include<iostream>
#include<algorithm>
using namespace std;

bool descending(int a, int b){
	return a > b;
}

int main()
{
	int n;
	cin >> n;
	
	int A[n], B[n];
	for(int i=0;i<n;i++) cin >> A[i];
	for(int i=0;i<n;i++) cin >> B[i];
	
	sort(A, A+n);
	sort(B, B+n, descending);
	
	int s=0;
	for(int i=0;i<n;i++) s += (A[i]*B[i]);
	
	cout << s;
	return 0;
}
