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
		a << '[';
		for (c s = u.h; s != u.n; ++s)
			*this << ", " + 2 * (s == u.h) << *s;
		ris << ']';
	}
	sim, class n mor pair <c,n> r) {ris << "(" << r.first << ", " << r.second << ")";}
	sim, class F mor rgm<c, F> u) {
		for (c s = u.h; s != u.n; ++s)
			u.f(*this, *s);
		ris;
	}
	#else
	sim mor const c&) {ris;}
	#endif
};
#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int MN = 52;
int in[MN][MN];
int out[MN][MN];
int n, m;
const int inf = 1e9;
sim> void mini(c & x, const c&y) {
	if (x > y) x = y;
}
using a4 = array<int, 4>;
vector <array<int, 4> > run(int board[MN][MN]) {
	vector <array<int, 4> > ans;
	for (int i = 1; i <= m; ++i) {
		array <int, 3> closest = {inf, 0, 0};
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k) {
				if ((j != k || j >= i) && board[j][k]) {
					debug << imie(j) imie(k);
					mini(closest, array<int, 3>{abs(j - i) + abs(k - i), j, k});
				}
			}
		debug << imie(i) imie(closest);
		assert(closest[0] != inf);
		int x = closest[1];
		int y = closest[2];
		if (x > y) {
			while (x < i) {
				ans.push_back(a4{x, y, x + 1, y});
				x++;
			}
			while (x > i) {
				ans.push_back(a4{x, y, x - 1, y});
				x--;
			}
			while (y < i) {
				ans.push_back(a4{x, y, x, y + 1});
				y++;
			}
			while (y > i) {
				ans.push_back(a4{x, y, x, y - 1});
				y--;
			}
		}
		else {
			while (y < i) {
				ans.push_back(a4{x, y, x, y + 1});
				y++;
			}
			while (y > i) {
				ans.push_back(a4{x, y, x, y - 1});
				y--;
			}
			while (x < i) {
				ans.push_back(a4{x, y, x + 1, y});
				x++;
			}
			while (x > i) {
				ans.push_back(a4{x, y, x - 1, y});
				x--;
			}
		}
		swap(board[i][i], board[closest[1]][closest[2]]);
	}
	return ans;
}
int per[MN];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		in[x][y] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		out[x][y] = i;
	}
	debug << "in = \n" << map_range(in + 1, in + n + 1, [&](muu &deb, int *x){deb << range(x + 1, x + n + 1) << "\n";}) ;
	debug << "out = \n" << map_range(out + 1, out + n + 1, [&](muu &deb, int *x){deb << range(x + 1, x + n + 1) << "\n";}) ;
	debug << "in";
	vector <a4> bef = run(in);
	debug << "out";
	vector <a4> aft = run(out);
	debug << imie(bef) imie(aft);
	vector <a4> ans = bef;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j)
			if (in[i][i] == out[j][j]) {
				per[i] = j;
				break;
			}
	}
	debug << "per = " << range(per + 1, per + m + 1);
	debug << "in = \n" << map_range(in + 1, in + n + 1, [&](muu &deb, int *x){deb << range(x + 1, x + n + 1) << "\n";}) ;
	debug << "out = \n" << map_range(out + 1, out + n + 1, [&](muu &deb, int *x){deb << range(x + 1, x + n + 1) << "\n";}) ;
	for (int i = 1; i <= m; ++i) {
		int to = per[i];
		int wh = i;
		if (to > i) {
			while (to != wh) {
				ans.push_back(a4{i, wh, i, wh + 1});
				wh++;
			}
		}
		else {
			while (to != wh) {
				ans.push_back(a4{i, wh, i, wh - 1});
				wh--;
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		int to = per[i];
		int wh = i;
		if (to > i) {
			while (to != wh) {
				ans.push_back(a4{wh, to, wh + 1, to});
				wh++;
			}
		}
		else {
			while (to != wh) {
				ans.push_back(a4{wh, to, wh - 1, to});
				wh--;
			}
		}
	}
	for (auto &x : aft) {
		swap(x[0], x[2]);
		swap(x[1], x[3]);
	}
	ans.insert(ans.end(), aft.rbegin(), aft.rend());
	printf("%d\n", (int)ans.size());
	for (a4 x : ans) {
		for (int i = 0; i < 4; ++i) printf("%d ", x[i]);
		printf("\n");
	}
}