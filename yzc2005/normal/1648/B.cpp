#include <bits/stdc++.h>
using namespace std;
int n, c, a[1000005], s[1000005];
bool v[1000005];
void solve() {
	scanf("%d%d", &n, &c);
	memset(v + 1, 0, c);
	memset(s + 1, 0, c * 4);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), v[a[i]] = s[a[i]] = 1;
	for (int i = 1; i <= c; ++i) s[i] += s[i - 1];
	for (int i = 1; i <= c; ++i) {
		bool f = false;
		for (int x = 1; i * x <= c; ++x)
			if (v[x]) f |= (s[min(c, (i + 1) * x - 1)] - s[i * x - 1] > 0);
		if (f && !v[i]) return puts("No"), void();
	}
	puts("Yes");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}