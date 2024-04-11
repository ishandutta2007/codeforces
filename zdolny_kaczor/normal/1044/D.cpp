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
const int nax = 2e5 + 44;
sim, class n> using used_map = map<c,n>;
used_map <int, int> u;
used_map <int, vector <int> > un;
used_map <int, int> val;
used_map <int, int> size;
void touch(int x) {
	if (u.count(x) == 0) {
		u[x] = x;
		size[x] = 1;
	}
}
int find(int x) {
	if (u[x] == x) return x;
	return u[x] = find(u[x]);
}
void flip(int x, int c) {
	debug << arr(val, x) << "^= " << imie(c);
	val[x] ^= c;
	for (int y : un[x])
		flip(y, c);
}
void onion(int aa, int bb, int c) {
	int a = find(aa);
	int b = find(bb);
	debug << imie(a) imie(b) imie(aa) imie(bb);
	if (a == b) {
		if ((val[aa] ^ val[bb]) != c)
			debug << arr(val, a) arr(val, b) imie(c) " contradiction";
		return;
	}
	if (size[a] > size[b])
		swap(a, b);
	flip(a, val[aa] ^ val[bb] ^ c);
	size[b] += size[a];
	un[b].push_back(a);
	u[a] = b;
}
int main() {
	int q;
	scanf("%d", &q);
	int last = 0;
	for (int _ = 0; _ < q; ++_) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l ^= last;
			r ^= last;
			x ^= last;
			if (l > r) swap(l, r);
			debug << "decoded info: " imie(l) imie(r) imie(x);
			r++;
			touch(l);
			touch(r);
			onion(l, r, x);
		}
		else {
			int l, r;
			scanf("%d%d", &l, &r);
			l ^= last;
			r ^= last;
			if (l > r) swap(l, r);
			debug << "decoded ask: " imie(l) imie(r);
			r++;
			if (u.count(l) && u.count(r) && find(l) == find(r)) {
				last = val[l] ^ val[r];
				printf("%d\n", last);
			}
			else {
				printf("-1\n");
				last = 1;
			}
		}
		debug << imie(u);
		debug << imie(val);
	}
}