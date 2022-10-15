#include <bits/stdc++.h>

const int SIZE = 1 << 21;
char buf[SIZE], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)
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
const int N = 1e6 + 5, B = 350, M = 1e5 + 5, B_2 = 350;

struct Ask {
	int opt, l, r, x, ans;
} Q[N];
int n, m, a[N];

int tmp[B + 5];
void Merge(int f[], int x, int g[], int y, int h[]) {
	int j = 1;
	for(int i = 1; i <= x; ++i) {
		for(; j <= y && a[g[j]] < a[f[i]]; ++j) tmp[i + j - 1] = g[j];
		tmp[i + j - 1] = f[i];
	}
	for(; j <= y; ++j) tmp[x + j] = g[j];
	for(int i = 1; i <= x + y; ++i)
		h[i] = tmp[i];
}

int L, R;
int	buk_d[B_2 + 5], buk_u[M], d_seq[B + 5], u_seq[B + 5], d_cnt, u_cnt, tag;
void Init() {
	memset(buk_d, 0, sizeof(buk_d));
	for(int i = 1; i <= u_cnt; ++i)
		buk_u[a[u_seq[i]]] = 0;
	tag = d_cnt = u_cnt = 0;
	for(int i = L; i <= R; ++i) {
		if(a[i] >= B_2) {
			++buk_u[a[i]];
			u_seq[++u_cnt] = i;
		} else {
			++buk_d[a[i]];
			d_seq[++d_cnt] = i;
		}
	}
	auto cmp = [&](const int &x, const int &y) { return a[x] < a[y]; };
	std::sort(u_seq + 1, u_seq + u_cnt + 1, cmp);
	std::sort(d_seq + 1, d_seq + d_cnt + 1, cmp);
}
int mov[B + 5];
void PushTag() {
	if(!u_cnt || a[u_seq[1]] - tag >= B_2) return;
	int cnt = 0;
	for(int i = 1; i <= u_cnt; ++i) {
		if(a[u_seq[i]] - tag < B_2) {
			--buk_u[a[u_seq[i]]];
			++buk_d[a[u_seq[i]] -= tag];
			mov[++cnt] = u_seq[i];
		} else
			u_seq[i - cnt] = u_seq[i];
	}
	Merge(d_seq, d_cnt, mov, cnt, d_seq);
	u_cnt -= cnt; d_cnt += cnt;
}
void Modify(int l, int r, int x) {
	if(!x) return;
	if(l != L || r != R) {
		PushTag();
		int cnt = 0;
		for(int i = 1; i <= d_cnt; ++i) {
			if(l <= d_seq[i] && d_seq[i] <= r && a[d_seq[i]] > x) {
				--buk_d[a[d_seq[i]]];
				++buk_d[a[d_seq[i]] -= x];
				mov[++cnt] = d_seq[i];
			} else d_seq[i - cnt] = d_seq[i];
		}
		Merge(d_seq, d_cnt - cnt, mov, cnt, d_seq);
		cnt = 0;
		for(int i = 1; i <= u_cnt; ++i) {
			if(l <= u_seq[i] && u_seq[i] <= r && a[u_seq[i]] - tag > x) {
				--buk_u[a[u_seq[i]]];
				++buk_u[a[u_seq[i]] -= x];
				mov[++cnt] = u_seq[i];
			} else u_seq[i - cnt] = u_seq[i];
		}
		Merge(u_seq, u_cnt - cnt, mov, cnt, u_seq);
		PushTag();
	} else {
		if(x >= B_2) {
			if(u_cnt && a[u_seq[u_cnt]] - tag > x) {
				int cnt = 0;
				for(int i = 1; i <= u_cnt; ++i) {
					if(a[u_seq[i]] - tag > x) {
						--buk_u[a[u_seq[i]]];
						++buk_u[a[u_seq[i]] -= x];
						mov[++cnt] = u_seq[i];
					} else u_seq[i - cnt] = u_seq[i];
				}
				Merge(u_seq, u_cnt - cnt, mov, cnt, u_seq);
			}
		} else {
			if(u_cnt) tag += x;
			if(d_cnt && a[d_seq[d_cnt]] > x) {
				int cnt = 0;
				for(int i = 1; i <= d_cnt; ++i) {
					if(a[d_seq[i]] > x) {
						--buk_d[a[d_seq[i]]];
						++buk_d[a[d_seq[i]] -= x];
						mov[++cnt] = d_seq[i];
					} else d_seq[i - cnt] = d_seq[i];
				}
				Merge(d_seq, d_cnt - cnt, mov, cnt, d_seq);
			}
		}
		PushTag();
	}
}
int Query(int l, int r, int x) {
	if(l != L || r != R) {
		PushTag();
		int ret = 0;
		if(x < B_2) {
			for(int i = 1; i <= d_cnt; ++i)
				if(l <= d_seq[i] && d_seq[i] <= r && a[d_seq[i]] == x) ++ret;
		} else {
			for(int i = 1; i <= u_cnt; ++i)
				if(l <= u_seq[i] && u_seq[i] <= r && a[u_seq[i]] - tag == x) ++ret;
		}
		return ret;
	} else if(x < B_2) {
		return buk_d[x];
	} else {
		return x + tag < M ? buk_u[x + tag] : 0;
	}
}
void Solve(int b) {
	L = std::max(b * B, 1);
	R = std::min((b + 1) * B - 1, n);
	Init();
	for(int i = 1; i <= m; ++i) {
		int opt = Q[i].opt, l = Q[i].l, r = Q[i].r, x = Q[i].x;
		l = std::max(l, L); r = std::min(r, R);
		if(l > r) continue;
		if(opt == 1) Modify(l, r, x);
		else Q[i].ans += Query(l, r, x);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		for(int i = 1; i <= m; ++i) {
			int opt, l, r, x; rd(opt, l, r, x);
			Q[i] = (Ask) { opt, l, r, x, 0 };
		}
		for(int i = 0; i <= n / B; ++i)
			Solve(i);
		for(int i = 1; i <= m; ++i)
			if(Q[i].opt == 2) printf("%d\n", Q[i].ans);
		//std::cerr << clock() * 1.0 / CLOCKS_PER_SEC << std::endl;
	} return 0;
}