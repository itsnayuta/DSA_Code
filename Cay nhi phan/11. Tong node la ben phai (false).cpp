#include<bits/stdc++.h>
using namespace std;
int n, check, sum;

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

bool isLeaf(node* root){
	if(root->right == NULL && root->left == NULL)
		return true;
	return false;
}


void is_Sum(node* root){
	if(root == NULL){
		return;
	}
	
	if(root -> right != NULL && isLeaf(root -> right))
		sum += root-> right -> data;
	
	if(root -> right != NULL && !isLeaf(root -> right))
		is_Sum(root -> right);
		
	if(root -> left != NULL && !isLeaf(root -> left))
		is_Sum(root -> left);
		
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		int par, child;
		char c;
		sum = 0;
		cin >> par >> child >> c;
		node *root = NULL;
		root = makeNode(par);
		buildTree(root, par, child, c);
		n--;
		while(n--){
			cin >> par >> child >> c;
			buildTree(root, par, child, c);
		}
		is_Sum(root);
		cout << sum << endl;
	}
}
