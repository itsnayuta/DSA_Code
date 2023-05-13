#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node *left = NULL;
	node *right = NULL;
};

node *makeNode(int i){
	node * newNode = new node;
	newNode -> data = i;
	newNode -> left = NULL;
	newNode -> right = NULL;
	
	return newNode;
}

void buildTree(node* &root, int val){
	if (root == NULL){
		root = makeNode(val);
	}
	else {
		if (root -> data > val) buildTree(root -> left, val);
		else buildTree(root -> right, val);
	}
}

void order(node* root){
	if (root != NULL){
		cout << root -> data << " ";
		if (root -> left != NULL) order(root -> left);
		if (root -> right != NULL) order(root -> right);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node *root = NULL;
		int val;
		while(n--){
			cin >> val;
			buildTree(root, val);
		}
		order(root);
		cout << endl;
	}
}
