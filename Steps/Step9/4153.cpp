#include<iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	while(a&&b&&c){
		a *= a;
		b *= b;
		c *= c;
		bool right=false;
		if(a==b+c || b==a+c || c==a+b) right=true;
		
		if(right) cout << "right"<<endl;
		else cout << "wrong"<<endl;
		cin >> a >> b >> c;
	}
	return 0;
}
