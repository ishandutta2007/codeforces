#include<bits/stdc++.h>
using namespace std;

string s[50];

int main() {
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> s[i];
	int lx = 1000, rx = -1, ly = 1000, ry = -1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j] == '*') {
				lx = min(lx, i);
				rx = max(rx, i);
				ly = min(ly, j);
				ry = max(ry, j);
			}
	for(int i=lx;i<=rx;i++, cout << '\n')
		for(int j=ly;j<=ry;j++)
			cout << s[i][j];

}