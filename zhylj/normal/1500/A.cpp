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
const int kB = 5e6 + 5, kN = 3e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, A[kN], tA[kN], idx[kN];
std::vector <pii> B[kB];

void Calc1() {
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			int t = A[i] + A[j];
			if(B[t].size() >= 2) B[t].pop_back();
			B[t].push_back(mkp(idx[i], idx[j]));
		}
	for(int i = 0; i < kB; ++i) {
		if(B[i].size() >= 2) {
			pii t1 = B[i].front(), t2 = B[i].back();
			if(t1.fi != t1.se && t2.fi != t2.se && t1.fi != t2.fi && t1.se != t2.se && t1.fi != t2.se && t1.se != t2.fi) {
				printf("YES\n%d %d %d %d\n", t1.fi, t1.se, t2.fi, t2.se);
				exit(0);
			}
		}
	}
}
void Calc2() {
	for(int i = 1; i < n; ++i) {
		B[A[i + 1] - A[i]].push_back(mkp(idx[i + 1], idx[i]));
	}
	for(int i = 0; i < kB; ++i) {
		if(B[i].size() >= 2) {
			pii t1 = B[i].front(), t2 = B[i].back();
			if(t1.fi != t1.se && t2.fi != t2.se && t1.fi != t2.fi && t1.se != t2.se && t1.fi != t2.se && t1.se != t2.fi) {
				printf("YES\n%d %d %d %d\n", t1.fi, t2.se, t2.fi, t1.se);
				exit(0);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(A[i]); idx[i] = i;
		}
		std::sort(idx + 1, idx + n + 1, [&](const int &x, const int &y) {
			return A[x] < A[y];
		});
		std::sort(A + 1, A + n + 1);
		if(n <= 7000) {
			Calc1();
		} else Calc2();
		printf("NO\n");
	} return 0;
}