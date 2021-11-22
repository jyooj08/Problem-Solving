#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int _data, Node* _left, Node* _right)
		: data(_data), left(_left), right(_right) {}
};

void insertNode(Node* root, int data) {
	if (root->data < data) {
		if (root->right == NULL) root->right = new Node(data, NULL, NULL);
		else insertNode(root->right, data);
	}
	else if (root->data > data) {
		if (root->left == NULL) root->left = new Node(data, NULL, NULL);
		else insertNode(root->left, data);
	}
}

Node* searchMinNodeInRight(Node* root) {
	if (root->left != NULL) return searchMinNodeInRight(root->left);
	else return root;
}

void deleteNode(Node* root, Node* parent, int target) {
	if (root == NULL) return;

	Node* removedNode;
	if (root->data < target) deleteNode(root->right, root, target);
	else if (root->data > target) deleteNode(root->left, root, target);
	else if(root->data == target) {
		if (root->left == NULL && root->right == NULL) {
			if (parent->left == root) parent->left = NULL;
			else if (parent->right == root) parent->right = NULL;
			delete root;
		}
		else if (root->left != NULL && root->right == NULL) {
			if (parent->left == root) parent->left = root->left;
			else if (parent->right == root) parent->right = root->left;
			delete root;
		}
		else if (root->left == NULL && root->right != NULL) {
			if (parent->left == root) parent->left = root->right;
			else if (parent->right == root) parent->right = root->right;
			delete root;
		}
		else if (root->left != NULL && root->right != NULL) {
			int tmp = searchMinNodeInRight(root->right)->data;
			deleteNode(root, parent, tmp);
			root->data = tmp;
		}
	}
	
}

void inorder_print(Node* root) {
	if (root == NULL) return;

	inorder_print(root->left);
	cout << root->data << ' ';
	inorder_print(root->right);
}

bool find(Node* root, int target) {
	if (root == NULL) return false;

	if (root->data == target) return true;
	else if (root->data < target) return find(root->right, target);
	else if (root->data > target) return find(root->left, target);
}

int main() {
	Node* tree = new Node(50, NULL, NULL);
	
	insertNode(tree, 10);
	insertNode(tree, 12);
	insertNode(tree, 87);
	insertNode(tree, 35);
	insertNode(tree, 100);
	insertNode(tree, 1);
	insertNode(tree, 22);
	insertNode(tree, 64);
	
	inorder_print(tree);

	cout << "\nfind 10: " << find(tree, 10) << endl;
	cout << "find 15: " << find(tree, 15) << endl;

	deleteNode(tree, NULL, 87);
	inorder_print(tree);
	return 0;
}
