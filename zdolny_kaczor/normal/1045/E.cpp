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
	#else
	sim mor const c&) {ris;}
	#endif
};
#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int MN = 1e3 + 44;
pair <int, int> coo[MN];
int col[MN];
int n;
int det(int a, int b, int c) {
	return (coo[a].first - coo[b].first) * (coo[a].second - coo[c].second) - 
		(coo[a].second - coo[b].second) * (coo[a].first - coo[c].first);
}
bool inside(int a, int b, int c, int i) {
	return abs(det(a, b, i)) + abs(det(b, c, i)) + abs(det(c, a, i)) == abs(det(a, b, c));
}
vector <pair <int, int> > ans;
void go(int a, int b, int c) {
	vector <int> points;
	for (int i = 0; i < n; ++i)
		if (i != a && i != b && i != c && inside(a, b, c, i))
			points.push_back(i);
	debug << arr(coo, a) arr(coo, b) arr(coo, c) imie(points);
	int more = (col[a] + col[b] + col[c]) >= 2;
	int oth = col[a] != more ? a : (col[b] != more ? b : c);
	assert(col[oth] != more);
	for (int x : points) {
		if (col[x] != more) {
			debug << arr(col, x) arr(col, oth) imie(more);
			ans.emplace_back(x, oth);
			go(a, b, x);
			go(b, c, x);
			go(c, a, x);
			return;
		}
	}
	int m = col[a] == more ? a : b;
	for (int x : points) {
		debug << arr(col, m) arr(col, x);
		ans.emplace_back(m, x);
	}
}
int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", &coo[i].first, &coo[i].second, col + i);
#ifdef LOCAL
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			for (int k = j + 1; k < n; ++k)
				if (det(i, j, k) == 0) {
					debug << arr(coo, i) arr(coo, j) arr(coo, k);
					assert(false);
				}
#endif
	vector <int> order;
	for (int i = 0; i < n; ++i)
		order.push_back(i);
	sort(order.begin(), order.end(), [](int i, int j){return coo[i] < coo[j];});
	vector <int> up, down;
	for (int i : order) {
		while (up.size() >= 2u && det(up.back(), up[up.size() - 2], i) >= 0)
			up.pop_back();
		while (down.size() >= 2u && det(down.back(), down[down.size() - 2], i) <= 0)
			down.pop_back();
		up.push_back(i);
		down.push_back(i);
	}
	reverse(down.begin(), down.end());
	up.pop_back();
	down.pop_back();
	vector <int> hull = up;
	for (int y : down)
		hull.push_back(y);
	debug << imie(hull);
	vector <int> last_one, last_zero;
	int H = hull.size();
	for (int i = 0; i < H; ++i) {
		int c1 = col[hull[i]];
		int c2 = col[hull[(i + 1) % H]];
		if (c1 == 0 && c2 == 1)
			last_zero.push_back(i);
		else if (c1 == 1 && c2 == 0)
			last_one.push_back(i);
	}
	debug << imie(last_one) imie(last_zero);
	if (last_one.size() >= 2u) {
		printf("Impossible\n");
		return 0;
	}
	if (last_one.size() == 1) {
		for (int i = 0; i < H; ++i)
			if (col[hull[i]] == col[hull[(i + 1) % H]])
				go(hull[col[hull[i]] == 0 ? last_one[0] : last_zero[0]], hull[i], hull[(i + 1) % H]);
		for (int i = 0; i < H; ++i)
			if (col[hull[i]] == col[hull[(i + 1) % H]]) {
				debug << arr(hull, i) arr(hull, (i + 1) % H);
				ans.emplace_back(hull[i], hull[(i + 1) % H]);
			}
	}
	else {
		int oth = -1;
		for (int i = 0; i < n; ++i)
			if (col[i] != col[hull[0]])
				oth = i;
		if (oth == -1)
			for (int i = 1; i < n; ++i)
				ans.emplace_back(0, i);
		else {
			for (int i = 0; i < H; ++i) {
				debug << imie(oth) arr(hull, i) arr(hull, (i + 1) % H);
				go(hull[i], hull[(i + 1) % H], oth);
			}
			for (int i = 0; i < H - 1; ++i) {
				ans.emplace_back(hull[i], hull[i + 1]);
				debug << imie(ans);
			}
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto x : ans) {
		printf("%d %d\n", x.first, x.second);
		assert(col[x.first] == col[x.second]);
	}
}