#include <bits/stdc++.h>

typedef long long ll;
typedef std::map <ll, int> map;
const int N = 100054;

int n, cnt = 0;
ll a[N], pos[N], sum[N];
map fy;
int count[N];

int main() {
	int i, q; ll l, r;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%lld", a + i);
	std::sort(a, a + n), n = std::unique(a, a + n) - a;
	for (i = 1; i < n; ++i) ++fy[a[i] - a[i - 1]];
	*sum = n;
	for (auto x : fy) {
		pos[++cnt] = x.first;
		count[cnt] = count[cnt - 1] + x.second;
		sum[cnt] = sum[cnt - 1] + (pos[cnt] - pos[cnt - 1] - 1) * (n - count[cnt - 1]) + (n - count[cnt]);
//		fprintf(stderr, "%d : %lld %d %lld\n", cnt,pos[cnt],count[cnt],sum[cnt]);
	}
	for (scanf("%d", &q); q; --q) {
		scanf("%lld%lld", &l, &r), r -= l;
		i = std::upper_bound(pos, pos + (cnt + 1), r) - pos - 1;
		printf("%lld ", sum[i] + (n - count[i]) * (r - pos[i]));
	}
	putchar(10);
	return 0;
}
/*
0	0	5	5	1 3 4 5  9	<
1	2	3	8	2     6 10	<
2	3	2	10	      7 11	<
3	3	2	12		  8 12
4	4	1	13		    13	<
5	4	1	14			14
6	4	1	15			15
*/