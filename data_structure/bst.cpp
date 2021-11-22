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

class BST {
private:
	Node* root;

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

		Node* removedNode =NULL;
		if (root->data < target) deleteNode(root->right, root, target);
		else if (root->data > target) deleteNode(root->left, root, target);
		else if (root->data == target) {
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

	bool findTarget(Node* root, int target) {
		if (root == NULL) return false;

		if (root->data == target) return true;
		else if (root->data < target) return findTarget(root->right, target);
		else if (root->data > target) return findTarget(root->left, target);
	}

public:

	BST()
		: root(NULL) {}

	void insert(int data) {
		if (root == NULL) root = new Node(data, NULL, NULL);
		else insertNode(root, data);
	}

	void remove(int data) {
		deleteNode(root, NULL, data);
	}

	void print() {
		inorder_print(root);
		cout << endl;
	}

	bool find(int target) {
		return findTarget(root, target);
	}
};



int main() {
	BST tree;
	tree.insert(10);
	tree.insert(12);
	tree.insert(87);
	tree.insert(35);
	tree.insert(100);
	tree.insert(1);
	tree.insert(22);
	tree.insert(64);

	tree.print();

	cout << "find 10: " << tree.find(10) << endl;
	cout << "find 15: " << tree.find(15) << endl;

	tree.remove(87);

	tree.print();

	return 0;
}

