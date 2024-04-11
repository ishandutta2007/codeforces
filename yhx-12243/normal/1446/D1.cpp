#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 200054, INF = 0x3f3f3f3f;

int n, key, Max, ans;
int a[N], b[N];
int freq[N];
int cnt = 0, test[N];
int buf_[N * 2], *pool = buf_ + N;

inline void up(int &x, const int y) {x < y ? x = y : 0;}

void solve(int minor) {
	int i, s = 0;
	memset(buf_, 63, sizeof buf_), pool[0] = 0;
	for (i = 1; i <= n; ++i) {
		s += (a[i] == key) - (a[i] == minor);
		if (pool[s] >= INF) pool[s] = i;
		if (b[i] == key) up(ans, i - pool[s]);
	}
}

int main() {
	int i;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		if (++freq[a[i]] > Max) b[i] = a[i], Max = freq[a[i]];
		else if (freq[a[i]] == Max) b[i] = -1, ans = i;
		else if (!~(b[i] = b[i - 1])) ans = i;
	}
	if (ans == n) return cout << n << '\n', 0;
	key = b[n];
	fprintf(stderr, "key = %d\n", key);
	for (i = 1; i <= n && i <= 100; ++i)
		if (i != key) solve(i);
	cout << ans << '\n';
	return 0;
}