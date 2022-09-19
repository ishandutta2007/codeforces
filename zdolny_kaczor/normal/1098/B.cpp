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
sim> void mini(c &a, c b) { if (a > b) a = b; }
sim> void maxi(c &a, c b) { if (a < b) a = b; }
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": ")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int nax = 3e5 + 44;
char xx[nax];
int d[4] = {0, 0, 1, 1};
char c[] = "ACGT";
vector <string> inv(const vector <string> &x) {
	vector <string> ans;
	int n = x.size();
	int m = x[0].size();
	ans.resize(m);
	for (int i = 0; i < m; ++i)
		ans[i].resize(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			ans[j][i] = x[i][j];
	return ans;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector <string> in, ans;
	bool inve = false;
	for (int i = 0; i < n; ++i) {
		scanf("%s", xx);
		in.emplace_back(xx);
	}
	int dist = n * m + 44;
	for (int it = 0; it < 2; ++it) {
		do {
			vector <string> curr(n);
			for (int i = 0; i < n; ++i)
				curr[i].resize(m);
			vector <char> col[2];
			for (int i = 0; i < 4; ++i)
				col[d[i]].push_back(c[i]);
			int cdist = 0;
			for (int i = 0; i < n; ++i) {
				int w1 = 0, w2 = 0;
				for (int j = 0; j < m; ++j) {
					if (col[i & 1][j & 1] != in[i][j])
						w1++;
					if (col[i & 1][(j ^ 1) & 1] != in[i][j])
						w2++;
				}
				cdist += min(w1, w2);
				if (w1 < w2)
					for (int j = 0; j < m; ++j)
						curr[i][j] = col[i & 1][j & 1];
				else
					for (int j = 0; j < m; ++j)
						curr[i][j] = col[i & 1][(j ^ 1) & 1];
			}
			debug << imie(cdist);
			if (cdist < dist) {
				swap(cdist, dist);
				swap(curr, ans);
				inve = it;
			}
		}
		while (next_permutation(d, d + 4));
		swap(m, n);
		if (it == 0)
			in = inv(in);
	}
	if (inve)
		ans = inv(ans);
	debug << imie(dist);
	for (auto & x : ans)
		printf("%s\n", x.c_str());
}