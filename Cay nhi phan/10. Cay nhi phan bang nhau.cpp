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

void is_Cmp(node *root1, node *root2){
	if (root1 == NULL || root2 == NULL || check == 0)
		return;
	if (root1 -> data != root2 -> data) {
		check = 0;
		return;
	}
	if ((root1 -> left != NULL && root2 -> left == NULL) || (root1 -> right == NULL && root2 -> right != NULL)){
		check = 0;
		return;
	}
	is_Cmp(root1 -> right, root2 -> right);
	is_Cmp(root1 -> left, root2 -> left);
}
int main(){
	int t; cin >> t;
	while(t--){
		// node 1
		cin >> n;
		check = 1;
		int par, child;
		char c;
		cin >> par >> child >> c;
		node *root1 = NULL;
		root1 = makeNode(par);
		buildTree(root1, par, child, c);
		n--;
		while(n--){
			cin >> par >> child >> c;
			buildTree(root1, par, child, c);
		}
		// node 2
		cin >> n;
		cin >> par >> child >> c;
		node *root2 = NULL;
		root2 = makeNode(par);
		buildTree(root2, par, child, c);
		n--;
		while(n--){
			cin >> par >> child >> c;
			buildTree(root2, par, child, c);
		}
		// compare
		is_Cmp(root1, root2);
		if (check == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
}
