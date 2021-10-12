#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int height[9];
	bool checked[9]; fill_n(checked, 9, true);

	for(int i=0;i<9;i++) cin >> height[i];
	sort(height, height+9);
	
	/*
	bool find=false;
	for(int i=0;i<8;i++){
		checked[i]=true;
		for(int j=i+1;j<9;j++){
			checked[j]=true;
			
			int sum=0;
			for(int k=0;k<9;k++) if(!checked[k]) sum += height[k];
			if(sum==100){
				find=true; break;
			}
			
			checked[j]=false;
		}
		if(find) break;
		
		checked[i]=false;
	}
	
	for(int i=0;i<9;i++) if(!checked[i]) cout << height[i] << '\n';
	*/
	
	int sum = 0;
	for(int i=0;i<9;i++) sum += height[i];
	
	for(int i=0;i<8;i++){
		for(int j=i+1;j<9;j++){
			if(sum - height[i] - height[j] == 100){
				checked[i]=false;
				checked[j]=false;
				
				for(int k=0;k<9;k++) if(checked[k]) cout << height[k] << '\n';
				return 0;
			}
		}
	}
	return 0;
}
