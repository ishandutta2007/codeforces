#include <bits/stdc++.h>
using namespace std;
int n;
string s[100005], t[100005];
bool v2[26][26], v3[26][26][26];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];
	for (int i = 1; i <= n; ++i) {
		t[i] = s[i];
		reverse(t[i].begin(), t[i].end());
		if (s[i] == t[i]) {
			cout << "YES" << "\n";
			return;
		}
	}
	memset(v2, false, sizeof v2);
	memset(v3, false, sizeof v3);
	bool f = false;
	for (int i = 1; i <= n; ++i) {
		for (auto &x : s[i])
			x -= 'a';
		if (s[i].length() == 2) {
			f |= v2[s[i][1]][s[i][0]];
			for (int j = 0; j < 26; ++j)
				f |= v3[s[i][1]][s[i][0]][j];
			v2[s[i][0]][s[i][1]] = true;
		} else {
			f |= v2[s[i][2]][s[i][1]];
			f |= v3[s[i][2]][s[i][1]][s[i][0]];
			v3[s[i][0]][s[i][1]][s[i][2]] = true;
		}
	}
	cout << (f ? "YES" : "NO") << "\n";
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}