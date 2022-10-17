#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;
set<int> S;

int main() {
	for(cin >> t; t; --t) {
		cin >> s; n = s.length();
		long long ans = 0;
		S.clear();
		for(int i = 0, x = 0; i < n; ++i) {
			x += (s[i] == '+' ? 1 : -1);
			if(x >= 0) continue;
			if(S.count(x)) continue;
			S.insert(x), ans += i + 1;
		} 
		cout << ans + n << endl;
	}
	return 0;
}