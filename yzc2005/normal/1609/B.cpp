#include <bits/stdc++.h>
using namespace std;
int n, q;
char s[100005];
int pre[100005][3][3], suf[100005][3][3];
void down(int &x, int y) {
	if (x > y) {
		x = y;
	}
}
int main() {
	cin >> n >> q;
	cin >> (s + 1);
	for (int i = 1; i <= n; ++i) {
		s[i] -= 'a';
	}
	int ans = 0;
	for (int i = 1; i <= n - 2; ++i) {
		ans += (s[i] == 0 && s[i + 1] == 1 && s[i + 2] == 2);
	}
	while (q--) {
		int i;
		char c;
		cin >> i >> c;
		for (int j = i - 2; j <= i; ++j) {
			if (j < 1) {
				continue;
			}
			ans -= (s[j] == 0 && s[j + 1] == 1 && s[j + 2] == 2);
		}
		s[i] = c - 'a';
		for (int j = i - 2; j <= i; ++j) {
			if (j < 1) {
				continue;
			}
			ans += (s[j] == 0 && s[j + 1] == 1 && s[j + 2] == 2);
		}
		cout << ans << "\n";
	}
	return 0;
}