#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int m, n, a[MAXN], b[MAXN];
int main(){
	scanf("%d %d", &m, &n);
	for(int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	sort(a, a + m);
	sort(b, b + n);

	long long sa = 0, sb = 0;
	for(int i = 0; i < m; i++)sa += a[i];
	for(int i = 0; i < n; i++)sb += b[i];

	long long r = 1LL << 60, ca = sa;
	for(int i = m - 1; i >= 0; i--){
		ca -= a[i];

		if(sb > 10000000000000L && (m - i) > 10000)continue;
		r = min(r, ca + sb * (m - i));
	}

	long long cb = sb;
	for(int i = n - 1; i >= 0; i--){
		cb -= b[i];

		if(sa > 10000000000000L && (n - i) > 10000)continue;
		r = min(r, cb + sa * (n - i));
	}

	printf("%I64d\n", r);

	return 0;
}