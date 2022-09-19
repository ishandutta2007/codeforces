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
const int nax = 1e6 + 44, A = 26;
char s[nax], a[nax], b[nax];
char per[A];
bool used[A];
int n, k;
void fill_any() {
	for (int i = 0; i < k; ++i)
		if (!used[i]) {
			debug << (char) ('a' + i) << " is unused";
			for (int j = 0; j < k; ++j)
				if (per[j] == -1) {
					per[j] = i;
					break;
				}
		}
}
bool can_a(int pos) {
	debug << imie(pos);
	if (pos == n) return true;
	if (per[s[pos]] != -1) {
		if (per[s[pos]] > a[pos])
			return true;
		else if (per[s[pos]] == a[pos])
			return can_a(pos + 1);
		else
			return false;
	}
	for (int j = a[pos] + 1; j < k; ++j)
		if (!used[j]) {
			per[s[pos]] = j;
			used[j] = true;
			return true;
		}
	if (used[a[pos]])
		return false;
	per[s[pos]] = a[pos];
	used[a[pos]] = true;
	bool r = can_a(pos + 1);
	if (r)
		return true;
	per[s[pos]] = -1;
	used[a[pos]] = false;
	return false;
}
bool can_b(int pos) {
	debug << imie(pos);
	if (pos == n) return true;
	if (per[s[pos]] != -1) {
		debug << "given " << (char)(s[pos] + 'a');
		if (per[s[pos]] < b[pos])
			return true;
		else if (per[s[pos]] == b[pos])
			return can_b(pos + 1);
		else
			return false;
	}
	for (int j = 0; j < b[pos]; ++j)
		if (!used[j]) {
			per[s[pos]] = j;
			used[j] = true;
			return true;
		}
	if (used[b[pos]])
		return false;
	per[s[pos]] = b[pos];
	used[b[pos]] = true;
	bool r = can_b(pos + 1);
	if (r)
		return true;
	per[s[pos]] = -1;
	used[b[pos]] = false;
	return false;
}
bool can_both(int pos) {
	debug << imie(pos);
	if (pos == n) {
		return true;
	}
	if (per[s[pos]] != -1) {
		debug << "found " << (char)(per[s[pos]] + 'a');
		if (per[s[pos]] < a[pos])
			return false;
		if (per[s[pos]] > b[pos])
			return false;
		if (per[s[pos]] == a[pos]) {
			if (per[s[pos]] == b[pos]) {
				debug << "must fit both";
				return can_both(pos + 1);
			}
			else {
				debug << "must fit a only";
				return can_a(pos + 1);
			}
		}
		else {
			if (per[s[pos]] == b[pos]) {
				debug << "must fit b only";
				return can_b(pos + 1);
			}
			else {
				debug << "fits automatically";
				return true;
			}
		}
	}
	for (int j = a[pos] + 1; j < b[pos]; ++j) {
		if (!used[j]) {
			debug << (char) ('a' + j) << " is good";
			per[s[pos]] = j;
			used[j] = true;
			return true;
		}
	}
	debug << "no good found :(";
	if (a[pos] == b[pos]) {
		debug << "must fit exactly";
		if (used[a[pos]]) {
			debug << "is already used";
			return false;
		}
		per[s[pos]] = a[pos];
		used[a[pos]] = true;
		return can_both(pos + 1);
	}
	else {
		if (!used[a[pos]]) {
			debug << "can try " << (char)('a' + a[pos]) << " from a";
			per[s[pos]] = a[pos];
			used[a[pos]] = true;
			bool r = can_a(pos + 1);
			if (r) {
				debug << "succeed";
				return true;
			}
			else
				debug << "failed";
			per[s[pos]] = -1;
			used[a[pos]] = false;
		}
		if (!used[b[pos]]) {
			debug << "can try " << (char)('a' + b[pos]) << " from b";
			per[s[pos]] = b[pos];
			used[b[pos]] = true;
			bool r = can_b(pos + 1);
			if (r) {
				debug << "succeed";
				return true;
			}
			else
				debug << "failed";
			per[s[pos]] = -1;
			used[b[pos]] = false;
		}
	}
	return false;
}
void solve() {
	memset(used, 0, sizeof(used));
	memset(per, -1, sizeof(per));
	scanf("%d%s%s%s", &k, s, a, b);
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		a[i] -= 'a';
		b[i] -= 'a';
		s[i] -= 'a';
	}
	bool poss = can_both(0);
	if (poss) {
		debug << map_range(per, per + k, [](muu &d, char c) {if (c == -1) d << "?"; else d << (char)(c + 'a');});
		printf("YES\n");
		fill_any();
		/*
		for (int i = 0; i < k; ++i) {
			assert(per[i] >= 0 && per[i] < k);
			for (int j = i + 1; j < k; ++j)
				assert(per[i] != per[j]);
		}
		*/
		for (int i = 0; i < k; ++i)
			putchar('a' + per[i]);
		printf("\n");
	}
	else {
//		assert(false);
		printf("NO\n");
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
}