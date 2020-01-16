#include<iostream>
#include<climits>
using namespace std;

int main()
{
	//initialize
	int n, m;
	cin >> n >> m;
	
	char** board = new char*[n];
	for(int i=0;i<n;i++) board[i] = new char[m];
	
	for(int i=0;i<n;i++){
		cin >> board[i];
	}
	
	//get number of painting
	int minPainting=INT_MAX, paint=0;
	for(int i=0;i<=n-8;i++){
		for(int j=0;j<=m-8;j++){		
			// first block is 'B'
			paint=0;
			for(int a=i;a<i+8;a++){
				for(int b=j;b<j+8;b++){
					if((a+b-i-j)%2==0 && board[a][b]=='W') paint++;
					else if ((a+b-i-j)%2==1 && board[a][b]=='B') paint++;
				}
			}
			if(minPainting > paint) minPainting = paint;
			
			// first block is 'W'
			paint=0;
			for(int a=i;a<i+8;a++){
				for(int b=j;b<j+8;b++){
					if((a+b-i-j)%2==0 && board[a][b]=='B') paint++;
					else if ((a+b-i-j)%2==1 && board[a][b]=='W') paint++;
				}
			}
			if(minPainting > paint) minPainting = paint;
		}
	}
	
	cout << minPainting;
	
	return 0;
}
