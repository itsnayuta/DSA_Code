#include<bits/stdc++.h>
using namespace std;

long long ans = INT_MIN;
struct node {
	long long data;
	node *left;
	node *right;
	
};

node *makeNode(int s){
	node *newNode = new node;
	newNode->data = s;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void buildTree(node* &root, int par, int child, char c){
	if(root != NULL){
		if(root->data == par){
			if(c == 'L')
				root->left = makeNode(child);
			else root->right = makeNode(child);
		}
		
		buildTree(root->left, par, child, c);
		buildTree(root->right, par, child, c);
	}
}


void maxSum(node* root){
	if(root!= NULL){
		maxSum(root->left);
		maxSum(root->right);
		
		if(root->left != NULL && root->right != NULL){
			ans = max(root->left->data + root->right->data + root->data, ans);
			
			root->data = max(root->left->data, root->right->data) + root->data;
			
		}
		
		else if(root->left != NULL){
			root->data += root->left->data;
		}
		else if(root->right != NULL){
			root->data += root->right->data;
		}
	}
}



int main(){
	int t;
	cin >> t;
	while(t--){
		ans = INT_MIN;
		int n;
		cin >> n;
		node *root = NULL;
		
		long long par, child;
		char c;
		cin >> par >> child >> c;
		
		root = makeNode(par);
		buildTree(root, par, child, c);
		n--;
		while(n--){
			cin >> par >> child >> c;
			buildTree(root, par, child, c);
		}
		
		maxSum(root);
		cout << ans << endl;
		delete root;	
	}
}

