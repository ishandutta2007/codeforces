#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 12;

string mp[MAX_N];

int row[MAX_N],col[MAX_N];

int main () {
	int n,m;
	cin >>n >> m;
	for (int i=0;n>i;i++) {
		string s;
		cin >> s;
		bool gett=false;
		for (int j=0;m>j;j++) {
			if (s[j] == 'S') {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	int rr=0,cc=0;
	for (int i=0;n>i;i++) {
		rr += row[i];
	}
	for (int i=0;m>i;i++) {
		cc += col[i];
	}
	cout<<n*m-cc*rr<<endl;
}