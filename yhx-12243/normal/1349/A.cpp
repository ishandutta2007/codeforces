#include <bits/stdc++.h>
#define EB emplace_back

typedef long long ll;
typedef std::vector <int> vector;
const int N = 200054;

int n;
int a[N];
int pn = 0, c[N], p[78540];
vector ag[N];

void sieve(int n) {
	int i, j, v;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++;
		for (j = 0; (v = i * p[j]) <= n && j <= c[i]; ++j) c[v] = j;
	}
}

void factor(int n) {
	int i, j;
	for (; n != 1; ) {
		i = c[n];
		for (j = 0; !(n % p[i]); n /= p[i], ++j);
		ag[i].EB(j);
	}
}

ll pw(int a, int n, ll c = 1) {for (; n; --n) c *= a; return c;}

int main() {
	int i; ll s = 1;
	scanf("%d", &n), sieve(N - 1);
	for (i = 1; i <= n; ++i) scanf("%d", a + i), factor(a[i]);
	for (i = 0; i < pn; ++i) {
		std::sort(ag[i].begin(), ag[i].end());
		if ((int)ag[i].size() == n) {
			s *= pw(p[i], ag[i][1]);
		} else if ((int)ag[i].size() == n - 1) {
			s *= pw(p[i], ag[i][0]);
		}
	}
	printf("%lld\n", s);
	return 0;
}