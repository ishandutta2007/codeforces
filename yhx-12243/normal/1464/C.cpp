#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 100054;

int n;
ll target, a[N];
char s[N];

inline bool check() {
	int i;
	if (n <= 1) return *a == target;
	target += a[n - 2] - a[n - 1], n -= 2;
	std::sort(a, a + n);
	for (i = 0; i < n; ++i) target += a[i];
	for (i = n - 1; i >= 0; --i)
		if (target >= 2 * a[i]) target -= 2 * a[i];
	return !target;
}

int main() {
	int i;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> target >> s;
	for (i = 0; i < n; ++i) a[i] = 1ll << (s[i] - 97);
	cout << (check() ? "Yes\n" : "No\n");
	return 0;
}