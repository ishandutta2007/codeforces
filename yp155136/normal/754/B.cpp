#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 16;

int mp[MAX_N][MAX_N];

int f(char c) {
	if (c=='x') return 1;
	else if (c=='o') return -1;
	else return 0;
}

int n;

bool check() {
	n=4;
	for (int i=1;n>=i;i++) {
		for (int j=1;n>=j;j++) {
			if (mp[i][j] == 1 && mp[i][j+1]==1 && mp[i][j+2] == 1) return true;
		}
	}
	for (int j=1;n>=j;j++) {
		for (int i=1;n>=i;i++) {
			if (mp[i][j] == 1 && mp[i+1][j]==1 && mp[i+2][j] == 1) return true;
		}
	}
	for (int i=1;n>=i;i++) {
		for (int j=1;n>=j;j++) {
			if (mp[i][j] == 1 && mp[i+1][j+1] == 1 && mp[i+2][j+2] == 1) return true;
		}
	}
	for (int i=3;n>=i;i++) {
		for (int j=1;n>=j;j++) {
			if (mp[i][j] == 1 && mp[i-1][j+1]==1 && mp[i-2][j+2] == 1)return true;
		}
	}
	return false;
}

int main () {
	string a;
	while (cin >> a) {
		int n=4;
		for (int i=1;n>=i;i++) {
			if (i!=1) cin >> a;
			for (int j=1;n>=j;j++) {
				mp[i][j] = f(a[j-1]);
			}
		}
		bool ans=false;
		for (int i=1;n>=i;i++) {
			for (int j=1;n>=j;j++) {
				if (mp[i][j] == 0) {
					mp[i][j] = 1;
					ans |= check();
					mp[i][j] = 0;
				}
			}
		}
		if (ans ) puts("YES");
		else puts("NO");
	}
}