#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5, MOD = 1e9 + 7;

char s[N], t[N];
int n, m, f[N], nxt[N], pos[N], s_f[N];
void GetNxt() {
	nxt[1] = 0;
	for(int i = 2, k = 0; i <= m; ++i) {
		while(k && t[k + 1] != t[i]) k = nxt[k];
		if(t[k + 1] == t[i]) ++k;
		nxt[i] = k;
	}
	for(int i = 1, k = 0; i <= n; ++i) {
		while(k && t[k + 1] != s[i]) k = nxt[k];
		if(t[k + 1] == s[i]) ++k;
		if(k == m) pos[i] = i - k + 1;
		else pos[i] = pos[i - 1];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1); m = strlen(t + 1);
		GetNxt();
		f[0] = 1; s_f[0] = 1;
		for(int i = 1; i <= n; ++i) {
			if(pos[i]) f[i] = s_f[pos[i] - 1];
			f[i] = (f[i] + f[i - 1]) % MOD;
			s_f[i] = (s_f[i - 1] + f[i]) % MOD;
		}
		printf("%d\n", (f[n] - 1 + MOD) % MOD);
	} return 0;
}