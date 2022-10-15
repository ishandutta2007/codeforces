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
const int N = 1.5e6 + 5, Inf = 0x3f3f3f3f, Mod = 1e9 + 7, Inv2 = 5e8 + 4;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m, n_cnt, a[N], tr[N][2], b_siz[N][31], siz[N];

void Insert(int x) {
	int cur = 0;
	for(int i = 30; ~i; --i) {
		int v = (x >> i) & 1;
		if(!tr[cur][v])
			tr[cur][v] = ++n_cnt;
		cur = tr[cur][v];
		for(int j = 0; j < 31; ++j)
			if((x >> j) & 1) ++b_siz[cur][j];
		++siz[cur];
	}
}
int Calc(int x, int mid) {
	int cur = 0, ret = 0;
	for(int i = 30; ~i; --i) {
		int u = (x >> i) & 1, t = (mid >> i) & 1, v = u ^ t;
		if(t == 0) ret += siz[tr[cur][v ^ 1]];
		cur = tr[cur][v];
		if(!cur) break;
	}
	ret += siz[cur];
	return ret;
}
bool Check(int mid) {
	ll tot = 0;
	for(int i = 1; i <= n; ++i)
		tot += Calc(a[i], mid);
	return tot / 2 >= m;
}
int Calc2(int x, int mid) {
	int cur = 0, ret = 0;
	for(int i = 30; ~i; --i) {
		int u = (x >> i) & 1, t = (mid >> i) & 1, v = u ^ t;
		if(t == 0) {
			int nxt = tr[cur][v ^ 1];
			for(int j = 0; j < 31; ++j) {
				if((x >> j) & 1)
					ret = (ret + (1LL << j) * (siz[nxt] - b_siz[nxt][j])) % Mod;
				else ret = (ret + (1LL << j) * b_siz[nxt][j]) % Mod;
			}
		}
		cur = tr[cur][v];
		if(!cur) break;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		if(!m) {
			printf("0\n");
			continue;
		}
		for(int i = 1; i <= n; ++i) rd(a[i]), Insert(a[i]);
		int L = 0, R = (1LL << 31) - 1, ans = 0; ll cnt = 0;
		while(L < R) {
			int mid = ((ll)L + R + 1) >> 1;
			if(Check(mid)) L = mid;
			else R = mid - 1;
		}
		for(int i = 1; i <= n; ++i) {
			cnt += Calc(a[i], L + 1);
			ans = (ans + Calc2(a[i], L)) % Mod;
		}
		cnt /= 2; ans = 1LL * ans * Inv2 % Mod;
		ans = (ans + 1LL * (m - cnt) % Mod * (L % Mod)) % Mod;
		printf("%d\n", ans);
	} return 0;
}