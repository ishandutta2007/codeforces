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
#define V std::vector
#define H std::priority_queue
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll QPow(ll a, ll b) {
	ll ans = 1, bas = a;
	for(; b; b >>= 1, bas = bas * bas % kMod) if(b & 1) ans = ans * bas % kMod;
	return ans;
}

int n, m, k, q, fa[kN]; char A[kN], B[kN];
int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) { fa[Find(y)] = Find(x); }
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		rd(n);
		scanf("%s%s", A + 1, B + 1);
		for(int i = 1; i <= 256; ++i) fa[i] = i;
		bool flag = true;
		int cnt = 0;
		for(int i = 1; i <= n; ++i) {
			if(A[i] > B[i]) flag = false;
			else if(Find(A[i]) != Find(B[i])) {
				++cnt;
				Merge(A[i], B[i]);
			}
		}
		if(!flag) {
			printf("-1\n");
		} else {
			printf("%d\n", cnt);
		}
	} return 0;
}