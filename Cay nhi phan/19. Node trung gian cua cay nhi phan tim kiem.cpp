#include <bits/stdc++.h>
using namespace std;
set<int> leaf;
struct node {
	int data;
	node *left = NULL;
	node *right = NULL;
};

node *makeNode(int i){
	node *newNode = new node;
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
		if(root -> data > val) buildTree(root -> left, val);
		else buildTree(root -> right, val);
	}
}

void order(node *root){
	if (root != NULL){
		if (root -> right != NULL || root -> left != NULL)
			leaf.insert(root -> data);
		
		if (root -> right != NULL) order(root -> right);
		if (root -> left != NULL) order(root -> left);
	}
	
}
int main(){
	int t; cin >> t;
	while(t--){
		leaf.clear();
		int n; cin >> n;
		int val;
		node *root = NULL;
		while(n--){
			cin >> val;
			buildTree(root, val);
		}
		order(root);
		cout << leaf.size();
		cout << endl;
	}
}
