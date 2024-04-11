#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 1e2 + 6;
string s[MAX_N];

int row[MAX_N],col[MAX_N];

int main () {
	int n;
	cin >> n;
	for (int i=0;n>i;i++) {
		cin >>s[i];
		for (int j=0;n>j;j++) {
			if (s[i][j] == 'E') {
				row[i]++;
				col[j]++;
			}
		}
	}
	bool _row=false,_col=false;
	for (int i=0;n>i;i++) {
		if (row[i] == n) {
			_row=true;
		}
		if (col[i]==n) {
			_col=true;
		}
	}
	if (_row && _col) {
		puts("-1");
		return 0;
	}
	if (_row) {
		for (int i=0;n>i;i++) {
			for (int j=0;n>j;j++) {
				if (s[j][i] == '.') {
					cout<<j+1<<' '<<i+1<<endl;
					break;
				}
			}
		}
		return 0;
	}
	for (int i=0;n>i;i++) {
		for (int j=0;n>j;j++) {
			if (s[i][j] == '.') {
				cout<<i+1<<' '<<j+1<<endl;
				break;
			}
		}
	}
}