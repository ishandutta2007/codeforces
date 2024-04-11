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
const int N = 2e5 + 5;

struct Bit {
	int tr[N];
	void Modify(int o, int v) {
		for(; o < N; o += o & -o)
			tr[o] += v;
	}
	void Clear(int o) {
		for(; o < N; o += o & -o)
			tr[o] = 0;
	}
	int Query(int o) {
		int ret = 0;
		for(; o; o -= o & -o)
			ret += tr[o];
		return ret;
	}
} T;

int n, m, c, tot, a[N], b[N], L[N], R[N];
std::vector <int> R_pos[N], L_pos[N], pos[N];
std::vector <pii> opt[N];
std::priority_queue <pii> q;
std::priority_queue <pii, std::vector <pii>, std::greater <pii> > q_l;

int GetAns() {
	int ret = n;
	for(int i = 1; i <= n + 1; ++i) {
		for(auto p : opt[i])
			T.Modify(p.fi, p.se);
		int l = i, r = n + 1;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(T.Query(mid) < tot) l = mid + 1;
			else r = mid;
		}
		if(l != n + 1) {
			ret = std::min(ret, l - i + 1);
		}
	}
	return ret;
}

void InsertMat(int x_l, int x_r, int y) {
	opt[x_l].push_back(mkp(y, 1));
	opt[x_r + 1].push_back(mkp(y, -1));
}
void Insert(int x, int y) {
	InsertMat(1, x, x);
	InsertMat(x + 1, y, y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		for(int i = 0; i <= n + 1; ++i) {
			a[i] = b[i] = 0;
			R_pos[i].clear(); L_pos[i].clear(); opt[i].clear();
			if(i) T.Clear(i);
			pos[i].clear();
		}
		while(!q.empty()) q.pop();
		while(!q_l.empty()) q_l.pop();
		rd(n, m); c = tot = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]); b[++c] = a[i];
		}
		for(int i = 1; i <= m; ++i) {
			int l, r; rd(l, r);
			L[i] = l; R[i] = r;
			R_pos[r].push_back(i);
			L_pos[l].push_back(i);
		}
		std::sort(b + 1, b + c + 1);
		c = std::unique(b + 1, b + c + 1) - b - 1;
		for(int i = 1; i <= n; ++i) {
			a[i] = std::lower_bound(b + 1, b + c + 1, a[i]) - b;
			pos[a[i]].push_back(i);
		}
		for(int i = 1; i <= c; ++i)
			pos[i].push_back(n + 1);
		for(int i = n; i; --i) {
			for(int j : R_pos[i])
				q.push(mkp(R[j], j));
			while(!q.empty() && L[q.top().se] > i)
				q.pop();
			if(!q.empty()) {
				int r = q.top().fi,
					nxt = *std::prev(std::upper_bound(pos[a[i]].begin(), pos[a[i]].end(), r));
				if(i != nxt) {
					Insert(i, nxt);
					++tot;
				}
			}
		}
		for(int i = 1; i <= n; ++i) {
			for(int j : L_pos[i])
				q_l.push(mkp(L[j], j));
			while(!q_l.empty() && R[q_l.top().se] < i)
				q_l.pop();
			if(!q_l.empty()) {
				int l = q_l.top().fi,
					nxt = *std::lower_bound(pos[a[i]].begin(), pos[a[i]].end(), l);
				if(i != nxt) {
					Insert(nxt, i);
					++tot;
				}
			}
		}
		if(!tot) printf("0\n");
		else printf("%d\n", GetAns());
	} return 0;
}