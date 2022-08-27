#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 200054;

int n, m;
int c[N];
char s[N], a[N], b[N];

void work() {
	int i; m = 0;
	cin >> n >> s;
	if (!(s[0] & s[n - 1] & 1)) {cout << "NO\n"; return;}
	for (i = 1; i < n - 1; ++i) if (!(s[i] & 1)) c[m++] = i;
	if (m & 1) {cout << "NO\n"; return;}
	a[0] = b[0] = '(', a[n - 1] = b[n - 1] = ')', a[n] = b[n] = 0;
	for (i = 0; i < m; i += 2)
		a[c[i]] = b[c[i + 1]] = '(', a[c[i + 1]] = b[c[i]] = ')';
	m = 0;
	for (i = 1; i < n - 1; ++i) if (s[i] & 1) c[m++] = i;
	for (i = 0; i < m / 2; ++i) a[c[i]] = b[c[i]] = '(';
	for (; i < m; ++i) a[c[i]] = b[c[i]] = ')';
	cout << "YES\n" << a << '\n' << b << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}