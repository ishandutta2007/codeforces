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

int n, A[kN], d[kN], f[kN], g[kN], st[kN], top = 0;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(A[i]);
		std::sort(A + 1, A + n + 1);
		for(int i = 1; i <= n; ++i) d[i] = A[i] ^ A[i - 1];
		int cnt = 0;
		for(int i = 2; i <= n; ++i) {
			//printf("Insert : %d\n", i);
			st[++top] = d[i];
			while(top > 1 && st[top] > st[top - 1]) {
				st[top - 1] ^= st[top]; --top;
				++cnt;
			}
			//for(int j = 1; j <= top; ++j) printf("%d ", st[j]);
			//printf("\n");
			f[i] = cnt;
		}
		for(int i = 1; i <= n; ++i) d[i] = A[i + 1] ^ A[i];
		cnt = 0; top = 0;
		for(int i = n - 1; i; --i) {
			st[++top] = d[i];
			while(top > 1 && st[top] > st[top - 1]) {
				st[top - 1] ^= st[top]; --top;
				++cnt;
			}
			g[i] = cnt;
		}
		int ans = kInf;
		/*for(int i = 1; i <= n; ++i) printf("%d ", f[i]);
		printf("\n");
		for(int i = 1; i <= n; ++i) printf("%d ", g[i]);
		printf("\n");*/
		for(int i = 1; i <= n; ++i) {
			ans = std::min(f[i] + g[i], ans);
		}
		printf("%d\n", ans);
	} return 0;
}