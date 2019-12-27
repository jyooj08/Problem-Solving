#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	
	for(int i=0;i<testcase;i++){
		char quiz[100];
		cin >> quiz;
		int len = strlen(quiz);
		int score=0, idx=0, next=0;
		
		for(int i=0;i<len;i++){
			if(quiz[idx] == 'O'){
				next++;
				score += next;
			} else{
				next = 0;
			}
			idx++;
		}
		cout << score << endl;
	}
	
	return 0;
}
