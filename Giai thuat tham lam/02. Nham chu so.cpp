#include<bits/stdc++.h>
using namespace std;
int _max(string a){
	for (int i = 0;  i < a.size(); i++){
		if (a[i] == '5') a[i] = '6';
	}
	return stoi(a);
}
int _min(string a){
	for (int i = 0; i < a.size(); i++){
		if (a[i] == '6') a[i] = '5';
	}
	return stoi(a);
}
int main(){
	string a, b; cin >> a >> b;
	cout << _min(a) + _min(b)<< " " << _max(a) + _max(b);
}
