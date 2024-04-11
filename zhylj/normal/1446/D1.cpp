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
const int kN = 4e5 + 5, kMov = 2e5 + 3, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, A[kN], cnt[kN], b[kN], nxt[kN], lst[kN];
std::vector <int> oc[kN], idx, tmp;

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		memset(b, 0x3f, sizeof(b));
		int mx_A = 0, ans = 0;
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(A[i]);
			++cnt[A[i]];
			oc[A[i]].push_back(i);
		}
		for(int i = 1; i <= n; ++i) oc[i].push_back(n + 1);
		for(int i = 1; i <= n; ++i)
			if(cnt[i] > cnt[mx_A]) mx_A = i;
		nxt[n] = n + 1;
		for(int i = n - 1; i; --i) {
			if(A[i + 1] != mx_A) nxt[i] = nxt[i + 1];
			else nxt[i] = i + 1;
		}
		lst[1] = 0;
		for(int i = 2; i <= n; ++i) {
			if(A[i - 1] != mx_A) lst[i] = lst[i - 1];
			else lst[i] = i - 1;
		}
		for(int i = 1; i <= n; ++i) {
			if(cnt[i] && i != mx_A) {
				int t = 0, mx = 0;
				idx.clear();
				std::reverse(idx.begin(), idx.end());
				for(int j = 0; j < oc[i].size() - 1; ++j) {
					tmp.clear();
					for(int p = lst[oc[i][j]], k = 1; p > mx && k <= cnt[i] + 2; p = lst[p], ++k)
						tmp.push_back(p);
					std::reverse(tmp.begin(), tmp.end());
					for(int k = 0; k < tmp.size(); ++k) idx.push_back(tmp[k]);
					for(int p = oc[i][j], k = 0; p < oc[i][j + 1] && k <= cnt[i] + 2; p = nxt[p], ++k)
						idx.push_back(p), mx = std::max(mx, p);
				}
				for(int j = 1; j <= idx.size(); ++j)
					b[kMov + j] = b[kMov - j] = kInf;
				b[kMov] = lst[idx[0]];
				idx.push_back(nxt[idx.back()]);
				for(int j = 0; j < idx.size() - 1; ++j) {
					int x = idx[j];
					if(A[x] == mx_A) ++t;
					else if(A[x] == i) --t;
					ans = std::max(ans, idx[j + 1] - 1 - b[kMov + t]);
					b[kMov + t] = std::min(b[kMov + t], x);
				}
			}
		}
		printf("%d\n", ans);
	} return 0;
}