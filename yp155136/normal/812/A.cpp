#include <iostream>
#include <stdio.h>
using namespace std;

bool a[4][4];

int main () {
	for (int i=0;4>i;i++) {
		for (int j=0;4>j;j++) {
			cin >> a[i][j];
		}
	}
	bool check=false;
	for (int i=0;4>i;i++) {
		bool haha=false;
		for (int j=0;3>j;j++) haha |= a[i][j];
		for (int j=i;i+3>j;j++) {
			haha |= a[(j+1)%4][j-i];
		}
		if (a[i][3] && haha) check=true;
	}
	if (check) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}