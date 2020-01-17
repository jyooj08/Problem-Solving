#include<iostream>
using namespace std;

int main()
{
	int testcase, repeat;
	string str;
	cin >> testcase;
	
	for(int i=0;i<testcase;i++){
		cin >> repeat >> str;
		int size = str.size();
		string newStr="";
		for(int j=0;j<size;j++){
			for(int r=0;r<repeat;r++){
				newStr += str[j];
			}
		}
		cout << newStr << endl;
	}
	return 0;
}
