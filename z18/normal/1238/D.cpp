#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5;
int n, a[maxn + 3], b[maxn + 3], id_a[maxn + 3], id_b[maxn + 3];
char s[maxn + 3];

ll solve(char s[]) {
	for (int i = 1; i <= n; i++) {
		id_a[i] = s[i - 1] == 'A' ? i - 1 : id_a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		id_b[i] = s[i - 1] == 'B' ? i - 1 : id_b[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + (s[i] == 'A');
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + (s[i] == 'B');
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'B') {
			ans += a[min(id_a[id_a[i]], id_a[id_b[i]])];
		}
	}
	return ans;
}

int main() {
	scanf("%d %s", &n, s + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + (s[i] == 'A');
	}
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + (s[i] == 'B');
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'A') {
			ans += a[i - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'B') {
			ans += b[i - 1];
		}
	}
	ans += solve(s);
	reverse(s + 1, s + n + 1);
	ans += solve(s);
	printf("%I64d\n", ans);
	return 0;
}