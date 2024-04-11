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
const int N = 1e6 + 5;

std::mt19937_64 rng(std::random_device {}());

int n, p[N], s[N], p_cnt; bool flag[N];
ull h[N], f[N];
std::map <ull, int> pre;

void Sieve() {
	for(int i = 2; i < N; ++i) {
		if(!flag[i]) {
			p[++p_cnt] = i;
			h[i] = rng();
			s[i] = i;
		}
		for(int j = 1; j <= p_cnt && i * p[j] < N; ++j) {
			flag[i * p[j]] = true;
			s[i * p[j]] = p[j];
			h[i * p[j]] = h[i] ^ h[p[j]];
			if(i % p[j] == 0) break;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n); Sieve();
		for(int i = 1; i <= n; ++i) {
			f[i] = f[i - 1] ^ h[i];
			pre[f[i]] = i;
		}
		ull tot = 0;
		for(int i = 1; i <= n; ++i) tot ^= f[i];
		if(tot == 0) {
			printf("%d\n", n);
			for(int i = 1; i <= n; ++i) printf("%d ", i);
			printf("\n");
		} else if(pre.count(tot)) {
			printf("%d\n", n - 1);
			for(int i = 1; i <= n; ++i)
				if(f[i] != tot) printf("%d ", i);
			printf("\n");
		} else {
			int x = 0, y = 0;
			for(int i = 1; i <= n; ++i)
				if(pre.count(tot ^ f[i])) {
					x = i; y = pre[tot ^ f[i]]; break;
				}
			if(x && y) {
				printf("%d\n", n - 2);
				for(int i = 1; i <= n; ++i)
					if(i != x && i != y) printf("%d ", i);
				printf("\n");
			} else {
				printf("%d\n", n - 3);
				for(int i = 1; i <= n; ++i)
					if(i != 2 && i != n && i != n / 2)
						printf("%d ", i);
				printf("\n");
			}
		}
	} return 0;
}