#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5;
int n, m, fact[maxn + 3];

int main() {
	scanf("%d %d", &n, &m);
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = 1ll * fact[i - 1] * i % m;
	}
	int cur = 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		cur = 1ll * i * cur % m;
		ans = (ans + 1ll * (n - i + 1) * (n - i + 1) % m * cur % m * fact[n - i]) % m;
	}
	printf("%d\n", ans);
	return 0;
}