#include<iostream>
using namespace std;

class Person{
public:
	int weight;
	int height;
	int rank;
};

class Heavy{
public:
	Person* people;
	int n;
	
	Heavy(int n){
		people = new Person[n];
		this->n=n;
	}
	
	void init(){
		for(int i=0;i<n;i++){
			cin >> people[i].weight >> people[i].height;
			people[i].rank=1;
		}
	}
	
	void rank(){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(people[i].weight < people[j].weight && people[i].height < people[j].height){
					people[i].rank++;
				}
			}
		}
	}
	
	void showRank(){
		for(int i=0;i<n;i++){
			cout << people[i].rank << ' ';
		}
	}
};

int main()
{
	int n;
	cin >> n;
	
	Heavy heavy(n);
	heavy.init();
	heavy.rank();
	heavy.showRank();
	
	return 0;
}
