#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		if(s.size() % 2 == 1 || s[0] == ')' || s.back() == '(')
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}