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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n; char str[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		scanf("%s", str + 1);
		n = strlen(str + 1);
		str[0] = '#'; str[n + 1] = '.';
		int cnt = 0;
		for(int i = 1; i <= n; ++i) {
			if(str[i - 1] != '$' && str[i - 1] == str[i + 1]) {
				++cnt;
				str[i + 1] = '$';
			}
			if(str[i] != '$' && str[i] == str[i + 1]) {
				++cnt;
				str[i + 1] = '$';
			}
		}
		printf("%d\n", cnt);
	} return 0;
}