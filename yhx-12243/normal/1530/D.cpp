#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::vector <int> vector;
const int N = 200054;

int n;
int a[N], b[N], c[N], u1[N], u2[N], u3[N];
int v1[N], v2[N];
bool used[N];

void work() {
	int i, c1 = 0, c2 = 0, c3 = 0, d1 = 0, d2 = 0, ans = 0, x;
	cin >> n;
	memset(b, 0, (n + 1) << 2);
	memset(c, 0, (n + 1) << 2);
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!c[a[i]]) c[a[i]] = i, b[i] = a[i], ++ans;
	}
	for (i = 1; i <= n; ++i) {
		if (b[i] && c[i]) ;
		else if (c[i]) u1[c1++] = i;
		else if (b[i]) u2[c2++] = i;
		else u3[c3++] = i;
	}
	if (!c1 && !c2 && c3 == 1)
		x = *u3, b[x] = x,
		std::swap(b[x], b[c[a[x]]]);
	else {
		for (i = 0; i < c3; ++i) v1[d1++] = v2[d2++] = u3[i];
		for (i = 0; i < c1; ++i) v1[d1++] = u1[i];
		for (i = 0; i < c2; ++i) v2[d2++] = u2[i];
		assert(d1 == d2), v2[d1] = *v2;
		for (i = 0; i < d1; ++i) b[v1[i]] = v2[i + 1];
	}
	cout << ans << '\n';
	for (i = 1; i <= n; ++i) cout << b[i] << (i == n ? '\n' : ' ');
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}