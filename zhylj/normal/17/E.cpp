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
const int kN = 4e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 51123987, k2Inv = (kMod + 1) / 2, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, d[kN]; ll s1[kN], s2[kN]; char str[kN];
void Manacher() {
	for(int i = 0, l = 0, r = 0; i <= 2 * n; ++i) {
		d[i] = r >= i ? std::min(d[l + r - i], r - i + 1) : 1;
		for(; i - d[i] >= 0 && i + d[i] <= 2 * n && str[i + d[i]] == str[i - d[i]]; ++d[i]);
		if(i + d[i] > r) l = i - d[i] + 1, r = i + d[i] - 1;
	}
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n); scanf("%s", str + 1);
		for(int i = n; i; --i) {
			str[2 * i - 1] = str[i];
			str[2 * i] = '#';
		}
		str[0] = '#';
		Manacher();
		ll ans = 0;
		for(int i = 1; i <= 2 * n - 1; ++i)
			ans = (ans + d[i] / 2) % kMod;
		ans = ans * (ans - 1) % kMod * k2Inv % kMod;
		for(int i = 1; i <= 2 * n - 1; ++i) {
			++s1[i]; --s1[i + d[i]];
			++s2[i]; if(i > d[i]) --s2[i - d[i]];
		}
		for(int i = 1; i <= 2 * n - 1; ++i)
			s1[i] = (s1[i] + s1[i - 1]) % kMod;
		for(int i = 2 * n - 1; i; --i)
			s2[i] = (s2[i] + s2[i + 1]) % kMod;
		for(int i = 2 * n - 1; i; --i)
			s2[i] = (s2[i] * (i & 1) + s2[i + 1]) % kMod;
		for(int i = 1; i <= 2 * n - 1; ++i) if(i & 1)
			ans = (ans - s1[i] * s2[i + 1] % kMod + kMod) % kMod;
		printf("%lld\n", ans);
	} return 0;
}