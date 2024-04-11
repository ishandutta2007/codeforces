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

int n, m, A[kN], B[kN], nxt[kN];

void GetNxt() {
	for(int i = 2, k = 0; i <= m; ++i) {
		while(k && B[k + 1] != B[i]) k = nxt[k];
		if(B[k + 1] == B[i]) ++k;
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
		for(int i = 1; i <= n; ++i) rd(A[i]);
		for(int i = 1; i <= m; ++i) rd(B[i]);
		--m;
		for(int i = 1; i <= n; ++i) A[i] -= A[i + 1];
		for(int i = 1; i <= m; ++i) B[i] -= B[i + 1];
		B[m + 1] = kInf;
		GetNxt();
		int cnt = 0;
		for(int i = 1, k = 0; i <= n; ++i) {
			while(k && B[k + 1] != A[i]) k = nxt[k];
			if(B[k + 1] == A[i]) ++k;
			if(k == m) ++cnt;
		}
		printf("%d\n", cnt);
	} return 0;
}