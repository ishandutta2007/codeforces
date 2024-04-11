#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 1e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	if(b < 0) return 0;
	ll ret = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ret = ret * bas % kMod;
	return ret;
}

int n, m, len, A[kN], nxt[kN]; char str[kN]; bool flag[kN];
void GetNxt() {
	nxt[1] = 0;
	for(int i = 2, k = 0; i <= len; ++i) {
		for(; k && str[i] != str[k + 1]; k = nxt[k]);
		if(str[i] == str[k + 1]) ++k;
		nxt[i] = k;
	}
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, m);
		scanf("%s", str + 1);
		if(m == 0) {
			printf("%d\n", QPow(26, n));
			return 0;
		}
		len = strlen(str + 1);
		for(int i = 1; i <= m; ++i) rd(A[i]);
		GetNxt();
		for(int i = len; i; i = nxt[i]) flag[i] = true;
		int res = n - len;
		for(int i = 2, r = A[1] + len - 1; i <= m; ++i) {
			if(A[i] <= r && !flag[r - A[i] + 1]) res = -1;
			res -= A[i] + len - 1 - std::max(r, A[i] - 1);
			r = A[i] + len - 1;
		}
		printf("%lld\n", QPow(26, res));
	} return 0;
}