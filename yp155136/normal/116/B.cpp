#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n,m;
	cin >> n >> m;
	string s[n+2];
	for (int i=0;n+2>i;i++) {
		s[i].resize(m+2);
	}
	for (int i=1;n>=i;i++) {
		string t;
		cin >>t;
		s[i] = " " + t + " ";
	}
	int dx[4] = {0,0,-1,1},dy[4]={1,-1,0,0};
	int ans=0;
	for (int i=1;n>=i;i++) {
		for (int j=1;m>=j;j++) {
			if (s[i][j] == 'W') {
				bool _=0;
				for (int k=0;4>k;k++) {
					int tx=i+dx[k],ty=j+dy[k];
					if (s[tx][ty] == 'P') _=1;
				}
				ans += _;
			}
		}
	}
	cout<<ans<<endl;
}