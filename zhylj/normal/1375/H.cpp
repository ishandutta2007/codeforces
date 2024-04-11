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
#define vec std::vector
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 3e6 + 5, kB = 1 << 8, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

pii opt[kN];
int n, q, cnt, A[kN], ans[kN];
vec <int> pos[kB];
vec <vec <int> > block_ans[kN];

int GetAns(const vec <int> &p, const vec <vec <int> > &tar_ans, int ql, int qr) {
	int l = std::lower_bound(p.begin(), p.end(), ql) - p.begin(),
		r = std::upper_bound(p.begin(), p.end(), qr) - p.begin() - 1;
	if(l > r) return 0;
	return tar_ans[l][r];
}
int Merge(int x, int y) {
	return x && y ? opt[++cnt] = mkp(x, y), cnt + n : x ^ y;
}
vec <vec <int> > Init(const vec <int> &p, int l, int r) {
	vec <vec <int> > ret(p.size(), vec <int> (p.size()));
	if(p.empty()) return ret;
	
	if(l == r) {
		ret[0][0] = p.front();
		return ret;
	}
	vec <int> p_l, p_r;
	int mid = (l + r) >> 1;
	for(auto i : p) {
		if(A[i] <= mid) p_l.push_back(i);
		else p_r.push_back(i);
	}
	vec <vec <int> > ans_l = Init(p_l, l, mid), ans_r = Init(p_r, mid + 1, r);
	for(int i = 0; i < p.size(); ++i) {
		for(int j = i; j < p.size(); ++j) {
			int x = GetAns(p_l, ans_l, p[i], p[j]), y = GetAns(p_r, ans_r, p[i], p[j]);
			ret[i][j] = Merge(x, y);
		}
	}
	return ret;
}

int Query(int l, int r) {
	int ret = 0;
	for(int i = 0; i < kB; ++i) {
		ret = Merge(ret, GetAns(pos[i], block_ans[i], l, r));
	}
	return ret;
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n, q);
		for(int i = 1; i <= n; ++i) rd(A[i]), --A[i];
		for(int i = 1; i <= n; ++i)
			pos[A[i] / kB].push_back(i);
		for(int i = 0; i < kB; ++i)
			block_ans[i] = Init(pos[i], i * kB, (i + 1) * kB - 1);
		for(int i = 1; i <= q; ++i) {
			int l, r; rd(l, r);
			ans[i] = Query(l, r);
		}
		printf("%d\n", cnt + n);
		for(int i = 1; i <= cnt; ++i) {
			printf("%d %d\n", opt[i].fi, opt[i].se);
		}
		for(int i = 1; i <= q; ++i) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	} return 0;
}