#include<bits/stdc++.h>
using namespace std;
int n, check;

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

void buildTree(node *root, int par, int child, char c){
	if (root != NULL){
		if (root -> data == par){
			if (c == 'L') 
				root -> left = makeNode(child);
			else root -> right = makeNode(child);
		}
		buildTree(root -> left, par, child, c);
		buildTree(root -> right, par, child, c);
	}
}

void is_Check(node *root){
	if(root != NULL){
		if((root -> left == NULL && root -> right != NULL) || (root -> left != NULL && root -> right == NULL)){
			check = 0;
			return;
		}
		is_Check(root -> left);
		is_Check(root -> right);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		check = 1;
		int par, child;
		char c;
		cin >> par >> child >> c;
		node *root = NULL;
		root = makeNode(par);
		buildTree(root, par, child, c);
		n--;
		while(n--){
			cin >> par >> child >> c;
			buildTree(root, par, child, c);
		}
		is_Check(root);
		if (check == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
}
