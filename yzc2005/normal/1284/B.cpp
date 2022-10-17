#include <bits/stdc++.h>
using namespace std;
#define rg register
#define fu(i, a, b) for(rg int i = a; i <= b; ++i)
#define fd(i, a, b) for(rg int i = a; i >= b; --i)
inline void read(int &x) {
	x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - 48, ch = getchar();
}
 
const int N = 100005;
int n, sum[N << 4], mn[N], mx[N], cnt;
bool flg[N];
long long ans;
 
int main() {
	read(n);
	for(int i = 1, len, a; i <= n; ++i) {
		read(len); mn[i] = 1e9;
		fu(j, 1, len) {
			read(a);
			if(a > mn[i]) flg[i] = 1;
			mn[i] = min(mn[i], a), mx[i] = max(mx[i], a);
		}
		if(flg[i]) {
			++cnt;
			continue;
		}
		sum[mn[i]]++;
	}
	fu(i, 0, 1e6) sum[i] += sum[i - 1];
	fu(i, 1, n) if(!flg[i]) ans += sum[mx[i] - 1];
	printf("%lld\n", ans + 2LL * cnt * n - 1LL * cnt * cnt);
	return 0;
}