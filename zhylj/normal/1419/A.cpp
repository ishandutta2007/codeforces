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
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, cnt[2]; char str[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		cnt[0] = cnt[1] = 0;
		rd(n);
		scanf("%s", str + 1);
		for(int i = 1; i <= n; ++i) {
			cnt[i % 2] += ((str[i] - '0') % 2) ^ (i % 2 == 0);
		}
		if(n % 2 == 0) printf(cnt[0] ? "2\n" : "1\n");
		else printf(cnt[1] ? "1\n" : "2\n");
	} return 0;
}