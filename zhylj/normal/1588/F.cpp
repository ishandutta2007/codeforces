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
const int N = 2e5 + 5, B = 450, D = N / B + 5;

struct Ask {
	int opt, x, y;
} Q[N];
int n, m, q, p[N]; ll a[N];

struct SqSum {
	ll s_bk[D], s_sg[N];
	void Init() {
		memset(s_bk, 0, sizeof(s_bk));
		memset(s_sg, 0, sizeof(s_sg));
	}
	void Modify(int x, ll y) { s_sg[x] += y; s_bk[x / B] += y; }
	ll Query(int l, int r) {
		ll ret = 0;
		if(l / B != r / B) {
			for(int i = l / B + 1; i < r / B; ++i) ret += s_bk[i];
			for(int i = l; i < (l / B + 1) * B; ++i) ret += s_sg[i];
			for(int i = r / B * B; i <= r; ++i) ret += s_sg[i];
		} else {
			for(int i = l; i <= r; ++i)
				ret += s_sg[i];
		}
		return ret;
	}
} T;

int s, seg[N], nxt[4 * B + D], cnt[4 * B + D][D];
ll tag[4 * B + D];
bool vis[N], flg[N];
void Calc() {
	memset(seg, 0, sizeof(seg));
	memset(vis, false, sizeof(vis));
	memset(flg, false, sizeof(flg));
	memset(cnt, 0, sizeof(cnt));
	memset(tag, 0, sizeof(tag));
	T.Init();
	s = 0;
	for(int i = 1; i <= q; ++i) {
		int opt = Q[i].opt, x = Q[i].x, y = Q[i].y;
		if(opt == 3) {
			flg[x] = flg[y] = flg[p[x]] = flg[p[y]] = true;
			std::swap(p[x], p[y]);
		}
	}
	for(int i = 1; i <= n; ++i) if(flg[i]) {
		seg[i] = ++s; vis[i] = true;
		for(int j = p[i]; !flg[j]; j = p[j]) {
			seg[j] = s; vis[j] = true;
		}
	}
	for(int i = 1; i <= n; ++i) if(!vis[i]) {
		int siz = 1; vis[i] = true;
		for(int j = p[i]; j != i; j = p[j]) {
			++siz; vis[j] = true;
		}
		if(siz >= B) {
			seg[i] = ++s;
			for(int j = p[i]; j != i; j = p[j])
				seg[j] = s;
		}
	}
	//std::cerr << s << " " << q << std::endl;
	for(int i = q; i; --i) {
		int opt = Q[i].opt, x = Q[i].x, y = Q[i].y;
		if(opt == 3) std::swap(p[x], p[y]);
	}
	for(int i = 1; i <= s; ++i) nxt[i] = i;
	for(int i = 1; i <= n; ++i) {
		if(seg[i]) {
			if(seg[p[i]] != seg[i])
				nxt[seg[i]] = seg[p[i]];
			++cnt[seg[i]][i / B];
		}
		T.Modify(i, a[i]);
	}
	for(int i = 1; i <= s; ++i)
		for(int j = 1; j <= n / B; ++j) cnt[i][j] += cnt[i][j - 1];
	for(int i = 1; i <= q; ++i) {
		int opt = Q[i].opt, x = Q[i].x, y = Q[i].y;
		if(opt == 1) {
			ll tot = T.Query(x, y);
			if(x / B != y / B) {
				for(int j = 1; j <= s; ++j)
					tot += (cnt[j][y / B - 1] - cnt[j][x / B]) * tag[j];
				for(int j = x; j < (x / B + 1) * B; ++j) tot += tag[seg[j]];
				for(int j = y / B * B; j <= y; ++j) tot += tag[seg[j]];
			} else {
				for(int j = x; j <= y; ++j)
					tot += tag[seg[j]];
			}
			printf("%lld\n", tot);
		} else if(opt == 2) {
			if(seg[x]) {
				x = seg[x];
				tag[x] += y;
				for(int j = nxt[x]; j != x; j = nxt[j])
					tag[j] += y;
			} else {
				T.Modify(x, y);
				for(int j = p[x]; j != x; j = p[j])
					T.Modify(j, y);
			}
		} else {
			std::swap(p[x], p[y]);
			x = seg[x]; y = seg[y];
			std::swap(nxt[x], nxt[y]);
		}
	}
	for(int i = 1; i <= n; ++i)
		a[i] = T.s_sg[i] + tag[seg[i]];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= n; ++i) rd(p[i]);
		rd(m);
		for(int i = 1; i <= m; ++i) {
			int opt, x, y; rd(opt, x, y);
			Q[++q] = (Ask) { opt, x, y };
			if(q >= B || i == m) {
				Calc();
				q = 0;
			}
		}
	} return 0;
}