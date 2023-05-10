
#include<bits/stdc++.h>
using namespace std;
int n;

struct node {
	int data;
	node *left;
	node *right;
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

void level_Order(node *root){
	queue<node*> qe;
	node *top;
	qe.push(root);
	while(!qe.empty()){
		top = qe.front();
		qe.pop();
		cout << top -> data << " ";
		if (top -> left != NULL) qe.push(top -> left);
		if (top -> right != NULL) qe.push(top -> right);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		node *root = NULL;
		int par, child;
		char c;
		cin >> par >> child >> c;
		
		root = makeNode(par);
		buildTree(root, par, child, c);
		n--;
		while(n--){
			cin >> par >> child >> c;
			buildTree(root, par, child, c);
		}
		level_Order(root);
		cout << endl;
	}
}
