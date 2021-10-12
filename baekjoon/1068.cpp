#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
	int parent;
	int idx;
	vector<int> children;
};

int erase;
Node nodes[51];

int DFS(Node node){
	if(node.children.empty()) return 1;
	if(node.children.size()==1 && node.children[0]==erase) return 1;
	
	int count=0;
	for(int i=0;i<node.children.size();i++){
		if(node.children[i] != erase) count += DFS(nodes[node.children[i]]);
	}
	return count;
}

int main()
{
	int n, k, root;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> k;
		nodes[i].idx=i;
		nodes[i].parent=k;
		nodes[k].children.push_back(i);
		if(k==-1) root=i;
	}
	
	cin >> erase;
	if(root == erase){
		cout << "0";
		return 0;
	}
	cout << DFS(nodes[root]);
	
	return 0;
}
