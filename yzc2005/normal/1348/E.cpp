#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, k, a, b;
long long sa, sb, ans;
bool f[N];

int main() {
	scanf("%d%d", &n, &k);
	f[0] = 1;
	while(n--) {
		scanf("%d%d", &a, &b);
		sa += a, sb += b;
		for(int i = k - 1; ~i; --i) if(f[i])
			for(int j = 0; j <= min(a, k); ++j) 
				if(k - j <= b) f[(i + j) % k] = 1;
	}
	ans = sa / k + sb / k, sa %= k, sb %= k;
	for(int i = 0; i <= sa; ++i)	
			if(k - i <= sb && f[i]) 
				printf("%lld", ans + 1), exit(0);
	printf("%lld", ans);
	return 0;
}