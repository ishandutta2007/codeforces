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
const int nax = 1e6 + 44;
using pii = pair <int, int>;
#define log __log_kloda
const int log = 20;
char s[nax], t[nax];
int kmr[nax][log];
#define hash __hash_e4JK
pii hash(int st, int len) {
	int l = 31 - __builtin_clz(len);
	debug << imie(l) imie(len);
	return make_pair(kmr[st][l], kmr[st + len - (1 << l)][l]);
}
int main() {
	scanf("%s%s", s, t);
	int zeros = 0, ones = 0;
	int ss = strlen(s), tt = strlen(t);
	for (int i = 0; i < ss; ++i)
		if (s[i] == '0') zeros++;
		else ones++;
	for (int i = 0; i < tt; ++i)
		kmr[i][0] = t[i];
	for (int l = 1; l < log; ++l) {
		vector <pair <pair <int, int>, int> > curr;
		for (int i = 0; i + (1 << (l - 1)) < tt; ++i) {
			curr.emplace_back(make_pair(kmr[i][l - 1], kmr[i + (1 << (l - 1))][l - 1]), i);
		}
		sort(curr.begin(), curr.end());
		int c = 0;
		for (int i = 0; i < (int)curr.size(); ++i) {
			if (i && curr[i].first != curr[i - 1].first)
				c++;
			kmr[curr[i].second][l] = c;
			debug << arr2(kmr, curr[i].second, l);
		}
	}
	int ans = 0;
	for (int r0 = 1; r0 * zeros < nax; ++r0) {
		if ((tt - r0 * zeros) % ones == 0) {
			int r1 = (tt - r0 * zeros) / ones;
			if (r1 <= 0) continue;
			debug << imie(r0) imie(r1);
			int pos = 0;
			set <pii> hash1;
			set <pii> hash2;
			bool fail = false;
			for (int i = 0; i < ss; ++i) {
				if (s[i] == '0') {
					pii curr = hash(pos, r0);
					debug << range(t + pos, t + pos + r0);
					pos += r0;
					hash1.insert(curr);
					if (hash1.size() > 1u) {
						fail = true;
						break;
					}
				}
				else {
					pii curr = hash(pos, r1);
					debug << range(t + pos, t + pos + r1);
					pos += r1;
					hash2.insert(curr);
					if (hash2.size() > 1u) {
						fail = true;
						break;
					}
				}
			}
			if (!fail && *hash1.begin() == *hash2.begin() && r1 == r0)
				fail = true;
			if (!fail) {
				debug << imie(r0) imie(r1);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}