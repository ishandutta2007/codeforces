#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
	for(cin >> t; t; --t) {
		cin >> s;
		int a = 0, b = 0;
		for(int i = 0; i < s.length(); ++i)
			if(s[i] == '0') ++a;
			else ++b;
		if(min(a, b) & 1) cout << "DA" << '\n';
		else cout << "NET" << '\n';
	}
	return 0;
}