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

int is_True(node *root){
	queue<pair<node*, int>> q;
	pair<node*, int> top;
	q.push({root, 0});
	int max = -1;
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		
		if(top.first->left == NULL)
		{
			if(max == -1)
				max = top.second;
			else if(top.second != max)
				return 0;
		}
		else q.push({top.first->left, top.second+1});
		
		if(top.first->right == NULL)
		{
			if(max == -1)
				max = top.second;
			else if(top.second != max)
				return 0;
		}
		else q.push({top.first->right, top.second+1});	
	}
	
	return 1;
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
		
		if (is_True(root) == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
}
