#include<bits/stdc++.h>
using namespace std;

int main() {
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(s[i][j] != s[2 - i][2 - j])
				return cout << "NO" << endl, 0;
	cout << "YES" << endl;
}