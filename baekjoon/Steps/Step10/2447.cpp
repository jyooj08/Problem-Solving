#include<iostream>
using namespace std;

void draw(bool** star, int n, int row, int col){
	int k = n/3;
	if(k==1){
		star[row+1][col+1]=false;
		return;
	}
	
	for(int i=row+k;i<row+2*k;i++){
		for(int j=col+k;j<col+2*k;j++)
		    star[i][j] = false;
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			draw(star, n/3, row+n/3*i, col+n/3*j);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	bool** star;
	star = new bool*[n];
	for(int i=0;i<n;i++) star[i] = new bool[n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		    star[i][j]=true;
	}
	
	draw(star,n,0,0);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) 
		    if(star[i][j]) cout << "*";
		    else cout <<" ";
		    cout << endl;
	}
	
	return 0;
}
