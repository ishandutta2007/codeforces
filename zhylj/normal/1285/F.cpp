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
const int N = 1e5 + 5;

struct Bit {
	std::vector <int> tr;
	void Resize(int siz) { tr.resize(siz + 1); }
	void Modify(int o, int v) {
		for(; o; o -= o & -o)
			tr[o] += v;
	}
	int Query(int o) {
		int ret = 0;
		for(; o < tr.size(); o += o & -o)
			ret += tr[o];
		return ret;
	}
} T[N];

int p[N], mu[N], p_cnt;
bool flag[N];
void Init() {
	mu[1] = 1;
	for(int i = 2; i < N; ++i) {
		if(!flag[i]) p[++p_cnt] = i, mu[i] = -1;
		for(int j = 1; j <= p_cnt && i * p[j] < N; ++j) {
			flag[i * p[j]] = true;
			if(i % p[j] == 0) break;
			mu[i * p[j]] = -mu[i];
		}
	}
}

int a[N], vis[N];
std::vector <int> f[N];

void Insert(int x) {
	for(int d : f[x])
		T[d].Modify(x / d, 1);
}
int Check(int x, int p) {
	int tot = 0;
	for(int d : f[x])
		tot += T[d].Query((p + d - 1) / d) * mu[d];
	return tot;
}
int Query(int x) {
	int l = 0, r = N - 1;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(Check(x, mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int n; rd(n); Init();
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			a[x] = 1;
		}
		for(int i = 1; i < N; ++i) {
			for(int j = i; j < N; j += i)
				f[j].push_back(i);
			T[i].Resize(N / i);
		}
		ll ans = 0;
		for(int g = N - 1; g; --g) {
			for(int i = g; i < N; i += g)
				if(a[i] && !vis[i / g]) {
					Insert(i / g);
					vis[i / g] = 1;
					ans = std::max(ans, 1LL * i * Query(i));
				}
		}
		printf("%lld\n", ans);
	} return 0;
}