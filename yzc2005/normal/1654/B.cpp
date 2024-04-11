#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
void solve() {
	string s;
	cin >> s;
	vector<int> c(26);
	int n = s.length();
	int pos = n - 1;
	for (int i = n - 1; ~i; --i) {
		int x = s[i] - 'a';
		if (c[x]) continue;
		pos = i;
		c[x] = 1;
	}
	for (int i = pos; i < n; ++i)
		cout << s[i];
	cout << "\n";
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}