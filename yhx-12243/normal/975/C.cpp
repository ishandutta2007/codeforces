#include <bits/stdc++.h>
#define N 200005
using namespace std;

typedef long long ll;

int n, q;
int a[N];
ll s[N];

int main() {
	int i; ll atk, cur = 0;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; ++i) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
	for (; q; --q) {
		scanf("%lld", &atk);
		if ((cur += atk) >= s[n]) {printf("%d\n", n); cur = 0; continue;}
		i = upper_bound(s + 1, s + (n + 1), cur) - s;
		printf("%d\n", n - i + 1);
	}
	return 0;
}