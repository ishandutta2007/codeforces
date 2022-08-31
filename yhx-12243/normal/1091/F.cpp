#include <bits/stdc++.h>
#define N 110000

typedef long long ll;

int n;
ll l[N];
char s[N];

int main() {
	int i; bool fy3 = false;
	ll pre3 = 0, pre5 = 0, ans = 0, fy, waste = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%lld", l + i);
	scanf("%s", s + 1);
	for (i = 1; i <= n; ++i)
		switch (s[i]) {
			case 'W': ans += 2 * l[i]; break;
			case 'G': ans += 3 * l[i]; break;
			case 'L': ans += l[i]; break;
		}
//	printf("ans = %lld\n", ans);
	for (i = 1; i <= n; ++i)
		switch (s[i]) {
			case 'W':
				pre3 += l[i], fy3 = true;
				break;
			case 'G':
				fy = std::min(pre3, l[i]);
				pre3 -= fy;
				pre5 += l[i] - fy;
				waste += fy;
				ans -= fy;
				break;
			case 'L':
//				printf("pre3 = %lld, waste = %lld, pre5 = %lld\n", pre3, waste, pre5);
				if (pre3 >= l[i])
					ans += l[i], pre3 -= l[i];
				else {
					ans += pre3, l[i] -= pre3, pre3 = 0;
					if (waste >= l[i])
						ans += l[i] * 2, pre5 += l[i], waste -= l[i];
					else {
						ans += waste * 2, pre5 += waste, l[i] -= waste, waste = 0;
						if (pre5 >= l[i])
							ans += l[i] * 2, pre5 -= l[i];
						else {
							ans += pre5 * 2, l[i] -= pre5, pre5 = 0;
							ans += (fy3 ? 3 : 5) * l[i];
						}
					}
				}
				break;
		}
	printf("%lld\n", ans);
	return 0;
}