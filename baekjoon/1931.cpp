#include<iostream>
#include<algorithm>
using namespace std;

class Conference{
public:
	int start;
	int end;
};

bool compareEndTime(Conference a, Conference b){
	if(a.end == b.end) return a.start < b.start; // ������ �ð��� ���ٸ� �� ���� �����ϴ� ȸ�ǰ� ���� 
	return a.end < b.end;
}

int main()
{
	int n;
	cin >> n;
	
	Conference con[n];
	for(int i=0;i<n;i++) cin >> con[i].start >> con[i].end;
	
	sort(con, con+n, compareEndTime);
	
	int count=0, last=0;
	for(int i=0;i<n;i++){
		if(con[i].start >= last){
			count++;
			last=con[i].end;
		}
	}
	cout << count;
	
	return 0;
}
