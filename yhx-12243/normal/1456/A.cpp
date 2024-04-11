#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int n, a, d;
int c_add, c_remove;
char s[N];
int S[2 * N];

void work() {
	int i, j; ll ans = LLONG_MAX;
	cin >> n >> a >> d >> s + 1 >> c_add >> c_remove;
	memset(S + (n + 1), 0, d << 2);
	for (i = n; i > 0; --i) S[i] = S[i + d] + !(s[i] & 1);
	for (i = 0, j = a; j <= n; ++i, ++j)
		ans = std::min(ans, (ll)c_remove * i + (ll)c_add * S[j]);
	cout << ans << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}