#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int Case, n;
long long a[N], b[N], c[N], ans;

int main() {
	scanf("%d", &Case); while(Case--) {
		scanf("%d", &n); ans = 0;
		for(int i = 1; i <= n; ++i) scanf("%lld%lld", &a[i], &b[i]), ans += a[i];
		for(int i = 1; i <= n; ++i) ans -= (c[i] = min(b[i], a[i == n ? 1 : i + 1]));
		printf("%lld\n", ans + *min_element(c + 1, c + n + 1));
	}
}