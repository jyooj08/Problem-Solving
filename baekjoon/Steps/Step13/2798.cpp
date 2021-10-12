#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, m, sum, temp;
	int* cards;
	
	cin >> n >> m;
	cards = new int[n];
	for(int i=0;i<n;i++) cin >> cards[i];
	
	sort(cards, cards+n);
	
	sum = cards[0]+cards[1]+cards[2];
	
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				temp = cards[i]+cards[j]+cards[k];
				if(temp > m) break;
				if(sum < temp) sum = temp;
			}
		}
	}
	
	cout << sum;
	
	return 0;
}
