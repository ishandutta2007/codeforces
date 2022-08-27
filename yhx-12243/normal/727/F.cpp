#include <bits/stdc++.h>
#define N 782
using namespace std;

typedef long long ll;

int n, q, b, i, j;
int a[N];
ll f[N][N], r;

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

int main(){
	scanf("%d%d", &n, &q);
	for(i = 1; i <= n; ++i) scanf("%d", a + i);
	memset(f, 63, sizeof f);
	f[n][0] = 0;
	for(i = n - 1; i >= 0; --i)
		for(j = 0; j <= n - i; ++j){
			f[i][j] = f[i + 1][j];
			j ? down(f[i][j], max(0ll, f[i + 1][j - 1] - a[i + 1])) : void(0);
		}
	for(; q; --q){
		scanf("%I64d", &r);
		i = upper_bound(*f, *f + (n + 1), r) - *f;
		printf("%d\n", n - i + 1);
	}
	return 0;
}