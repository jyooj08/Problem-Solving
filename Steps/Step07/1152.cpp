#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char str[1000000];
	int num=1;
	
	cin.getline(str, 1000000);
	int len = strlen(str);
	
	for(int i=0;i<len;i++){
		if(str[i]==' ') num++;
	}
	
	if(str[0]==' ') num--;
	if(str[len-1]==' ') num--;
	cout << num;
	return 0;
}
