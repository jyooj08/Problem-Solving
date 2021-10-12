#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Member{
public:
	int age;
	string name;
	int order;
};

bool compareMember(Member a, Member b){
	if(a.age != b.age) return a.age < b.age;
	
	return a.order < b.order;
}

int main()
{
	int n;
	cin >> n;
	
	Member members[n];
	int ageHistogram[201] = {0,};
	
	cin >> members[0].age >> members[0].name; 
	members[0].order = ageHistogram[members[0].age]++;
	for(int i=1;i<n;i++){
		cin >> members[i].age >> members[i].name;
		members[i].order = ageHistogram[members[i].age]++;
	}
	
	sort(members, members+n, compareMember);
	
	for(int i=0;i<n;i++) cout << members[i].age<<' '<<members[i].name<<'\n';
	
	return 0;
}
