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
const int nax = 5e5 + 44;
string in[nax];
int lcp[nax];
char str[nax];
int n;
void pop(int x) {
	if (x != n - 1 && lcp[x] == in[x].size())
		lcp[x]--;
	if (x && lcp[x - 1] == in[x].size())
		lcp[x - 1]--;
	in[x].pop_back();
}
void fix(int k) {
	if (k == -1) return;
	if (lcp[k] != in[k].size() && (lcp[k] == in[k + 1].size() || in[k][lcp[k]] > in[k + 1][lcp[k]])) {
		int r = in[k].size() - lcp[k];
		for (int i = 0; i < r; ++i)
			pop(k);
		fix(k - 1);
	}	
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", str);
		in[i] = str;
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int k = 0; k < (int)min(in[i].size(), in[i + 1].size()); ++k)
			if (in[i][k] == in[i + 1][k])
				lcp[i] = k + 1;
			else
				break;
	}
	debug << range(lcp, lcp + n - 1);
	for (int i = 0; i < n - 1; ++i) {
		fix(i);
		debug << range(in, in + i + 2);
	}
	for (int i = 0; i < n; ++i)
		printf("%s\n", in[i].c_str());
}