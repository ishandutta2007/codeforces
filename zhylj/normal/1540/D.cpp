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
const int N = 1e5 + 5, B = 320;

struct Ask {
	int opt, x, y;
} Q[N];
int n, q, b[N], _b[N];

void Sort(std::vector <int> &p) {
    std::vector <int> bk[B], bk_2[B];
	for(int i : p)
		bk[Q[i].y % B].push_back(i);
	for(int i = 0; i < B; ++i)
		for(int j : bk[i]) bk_2[Q[j].y / B].push_back(j);
	p.clear();
	for(int i = 0; i < B; ++i)
		for(int j : bk_2[i]) p.push_back(j);
}

void Split(std::vector <pii> f, int x,
		std::vector <pii> &f_l, std::vector <pii> &f_r) {
	f_l.clear(); f_r.clear();
	int j = 0;
	for(pii i : f) {
		if(i.se <= x) f_l.push_back(mkp(i.fi - j, i.se));
		else f_r.push_back(i), ++j;
	}
}
void Merge(std::vector <pii> f_l, std::vector <pii> f_r,
		std::vector <pii> &f) {
	f.clear();
	int j = 0;
	for(int i = 0; i < f_l.size(); ++i) {
		for(; j < f_r.size() && f_r[j].fi <= f_l[i].fi + j; ++j)
			f.push_back(f_r[j]);
		f.push_back(mkp(f_l[i].fi + j, f_l[i].se));
	}
	for(; j < f_r.size(); ++j)
		f.push_back(f_r[j]);
}

std::vector <pii> f;
std::vector <int> p;
void Modify(int x, int y) {
	if(b[x] == y) return;
	std::vector <pii> f_l, f_x, f_r;
	Split(f, x - 1, f_l, f_r);
	Split(f_r, x, f_x, f_r);
	f_x[0].fi += y - b[x];
	Merge(f_x, f_r, f_r);
	Merge(f_l, f_r, f);
	b[x] = y;
}
void Jump() {
	if(p.empty()) return;
	Sort(p);
	std::vector <pii> p_f;
	for(int i : p) p_f.push_back(mkp(Q[i].y, -i));
	Merge(p_f, f, p_f);
	for(pii i : p_f)
		if(i.se < 0) Q[-i.se].y = i.fi;
	p.clear();
}

void Solve(int L, int R) {
	f.clear(); p.clear();
	for(int i = R; i >= L; --i)
		Merge((std::vector <pii>) { mkp(b[i] + 1, i) }, f, f);
	for(int i = 1; i <= q; ++i) {
		int opt = Q[i].opt, x = Q[i].x, y = Q[i].y;
		if(opt == 1) {
			if(x > R || x < L) continue;
			Jump();
			Modify(x, y);
		} else if(opt == 2) {
			if(x > R) continue;
			if(x > L) {
				for(int j = std::max(L, x); j <= R; ++j)
					Q[i].y += (Q[i].y >= b[j] + 1);
			} else p.push_back(i);
		}
	}
	Jump();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(b[i]), b[i] = i - 1 - b[i];
		memcpy(_b, b, sizeof(_b));
		rd(q);
		for(int i = 1; i <= q; ++i) {
			int opt, x; rd(opt, x);
			if(opt == 1) {
				int y; rd(y); y = x - 1 - y;
				Q[i] = (Ask) { opt, x, y };
				b[x] = y;
			} else {
				Q[i] = (Ask) { opt, x + 1, b[x] + 1 };
			}
		}
		memcpy(b, _b, sizeof(b));
		for(int i = 0; i <= n / B; ++i) {
			int L = std::max(i * B, 1),
				R = std::min((i + 1) * B - 1, n);
			Solve(L, R);
		}
		for(int i = 1; i <= q; ++i)
			if(Q[i].opt == 2) printf("%d\n", Q[i].y);
	} return 0;
}