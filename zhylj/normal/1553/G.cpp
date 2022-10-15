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
const int N = 1e6 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int A[N], p[N], fa[N], s[N], cnt; bool flag[N];
void Sieve() {
	for(int i = 2; i < N; ++i) {
		if(!flag[i]) {
			p[++cnt] = i;
			s[i] = i;
		}
		for(int j = 1; j <= cnt && i * p[j] < N; ++j) {
			flag[i * p[j]] = true;
			s[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
}
int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) { fa[Find(x)] = Find(y); }
void GetPf(int x, std::vector <int> &R) {
	while(x != 1) {
		int tmp = s[x];
		R.push_back(tmp);
		while(x % tmp == 0) x /= tmp;
	}
}
std::set <pii> Set;
int Query(int x, int y) {
	std::vector <int> R1, R2;
	GetPf(x, R1); GetPf(y, R2);
	for(auto i : R1) for(auto j : R2)
		if(Find(i) == Find(j)) return 0;
	for(auto i : R1) for(auto j : R2) {
		int fi = Find(i), fj = Find(j);
		if(Set.count(mkp(fi, fj))) return 1;
	}
	return 2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int n, q; rd(n, q);
		for(int i = 1; i <= n; ++i) rd(A[i]);
		Sieve();
		for(int i = 1; i < N; ++i) fa[i] = i;
		for(int i = 1; i <= n; ++i) {
			std::vector <int> R;
			GetPf(A[i], R);
			for(int j = 0; j + 1 < R.size(); ++j)
				Merge(R[j], R[j + 1]);
		}
		for(int i = 1; i <= n; ++i) {
			std::vector <int> R;
			GetPf(A[i], R);
			GetPf(A[i] + 1, R);
			for(auto j : R)
				for(auto k : R)
					Set.insert(mkp(Find(j), Find(k)));
		}
		while(q--) {
			int x, y; rd(x, y);
			printf("%d\n", Query(A[x], A[y]));
		}
	} return 0;
}