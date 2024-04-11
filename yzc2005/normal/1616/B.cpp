#include <bits/stdc++.h>
using namespace std;
void solve() {
	string s;
	int n;
	cin >> n;
	cin >> s;
	string t;
	t += s[0];
	for (int i = 1; i < n && (s[i] < t.back() || (i > 1 && s[i] == t.back())); ++i)
		t += s[i];
	cout << t;
	reverse(t.begin(), t.end());
	cout << t << "\n";	
}
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}