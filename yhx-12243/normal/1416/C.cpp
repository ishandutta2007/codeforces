#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef long long ll;
typedef std::vector <int> vector;
const int N = 300054;

int n;
int a[N];
ll I[2][N];

void partition(int dep, const vector &a) {
	if (!~dep || a.empty()) return;
	vector s0, s1; 
	for (int x : a)
		if (x >> dep & 1)
			I[1][dep] += s0.size(), s1.EB(x);
		else
			I[0][dep] += s1.size(), s0.EB(x);
	partition(dep - 1, s0), partition(dep - 1, s1);
}

int main() {
	int i, x; ll ans = 0; vector v;
	cin >> n, v.reserve(n);
	for (i = 0; i < n; ++i) cin >> x, v.EB(x);
	partition(29, v);
	for (x = i = 0; i < 30; ++i)
		if (I[0][i] <= I[1][i])
			ans += I[0][i];
		else
			ans += I[1][i], x |= 1 << i;
	cout << ans << ' ' << x << '\n';
	return 0;
}