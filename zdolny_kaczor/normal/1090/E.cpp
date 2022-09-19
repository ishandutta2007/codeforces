//Konrad Paluszek, University of Warsaw (former XIV LO Warsaw)
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<< (
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)), muu&>::type operator<<(c g) {
sim> struct rge {c h, n;};
sim> rge<c> range(c h, c n) {return rge<c>{h, n};}
sim, class F> struct rgm {c h, n; F f;};
sim, class F> rgm<c, F> map_range(c b, c e, F f) {return rgm<c, F>{b, e, f};}
sim, class F> rgm<typename c::const_iterator, F> map_range(const c &x, F f) {return map_range(x.begin(), x.end(), f);}
sim> auto dud(c *r) -> decltype(cerr << *r);
sim> char dud(...);
struct muu {
#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << '{';
		for (c s = u.h; s != u.n; ++s)
			*this << ", " + 2 * (s == u.h) << *s;
		ris << '}';
	}
	sim, class n mor pair <c,n> r) {ris << "(" << r.first << ", " << r.second << ")";}
	sim, class F mor rgm<c, F> u) {
		for (c s = u.h; s != u.n; ++s)
			u.f(*this << ", " + 2 * (s == u.h), *s);
		ris;
	}
	#else
	sim mor const c&) {ris;}
	#endif
	muu & operator()() {ris;}
};
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": ")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
vector <pair <int, int> > moves;
const int nax = 8;
bool is[nax][nax];
void add(int x1, int y1, int x2, int y2) {
	debug << imie(x1) imie(y1) imie(x2) imie(y2);
	assert(is[x1][y1]);
	assert(!is[x2][y2]);
	is[x1][y1] = false;
	is[x2][y2] = true;
	moves.emplace_back(x1 * 8 + y1, x2 * 8 + y2);
}
int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[8] = {2, 1, -2, -1, -2, -1, 2, 1};
int last[nax][nax];
int timer = 0;
bool dfs(int x, int y, int lx, int ly, int dep) {
	debug << imie(x) imie(y) imie(lx) imie(ly) imie(dep);
	if (is[x][y]) {
		return true;
	}
	if (dep == 0) {
		return false;
	}
	if (last[x][y] == timer) {
		return false;
	}
	last[x][y] = timer;
	for (int i = 0; i < 8; ++i) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && yy >= 0 && xx < nax && yy < nax && make_pair(yy, xx) >= make_pair(ly, lx)) {
			if (dfs(xx, yy, lx, ly, dep - 1)) {
				add(xx, yy, x, y);
				return true;
			}
		}
	}
	return false;
}
void move_to(int x, int y) {
	for (int d = 1; d < 60; ++d) {
		debug << "go with " imie(d);
		timer++;
		if (dfs(x, y, x, y, d))
			return;
	}
	assert(false);
}
void solve(int n) {
	for (int i = 0; i < n; ++i) {
		int x = i % 8, y = i / 8;
		debug << imie(x) imie(y);
		move_to(x, y);
	}
}
pair <int, int> get() {
	static char a[3];
	scanf("%s", a);
	return make_pair(a[0] - 'a', a[1] - '1');
}
int main() {
	int n;
	scanf("%d", &n);
	if (n < 32) {
		for (int i = 0; i < n; ++i) {
			pair <int, int> c = get();
			is[c.first][c.second] = true;
		}
		solve(n);
		printf("%d\n", (int)moves.size());
		for (pair <int, int> m : moves) {
			printf("%c%d-%c%d\n", m.first / 8 + 'a', m.first % 8 + 1, m.second / 8 + 'a', m.second % 8 + 1);
		}
	}
	else {
		memset(is, 1, sizeof(is));
		for (int i = 0; i < n; ++i) {
			pair <int, int> c = get();
			is[7 - c.first][7 - c.second] = false;
		}
		solve(64 - n);
		printf("%d\n", (int)moves.size());
		for (pair <int, int> m : moves) {
			printf("%c%d-%c%d\n", 'h' - m.second / 8, 8 - m.second % 8, 'h' - m.first / 8, 8 - m.first % 8);
		}
	}
}