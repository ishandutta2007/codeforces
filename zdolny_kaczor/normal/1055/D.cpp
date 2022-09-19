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
const int MN = 3e3 + 44;
char a[MN][MN], b[MN][MN];
bool same[MN];
pair <int, int> diff[MN];
void err() {
	printf("NO\n");
	exit(0);
}
const int B = 147, M = 1.5e9 + 1;
long long powe = 1;
int search(char * x, int len, long long hash) {
	debug << imie(x) imie(len) imie(hash) imie(powe);
	long long seen = 0;
	for (int i = 0; i < len; ++i) {
		seen = (x[i] + seen * B) % M;
	}
	debug << imie(seen);
	if (seen == hash) {
		debug << "return 0";
		return 0;
	}
	for (int i = 0; x[i + len]; i++) {
		seen = ((seen * B - x[i] * powe) + x[i + len]) % M;
		if (seen < 0)
			seen += M;
		debug << imie(seen);
		if (seen == hash) {
			debug << "return " << i + 1;
			return i + 1;
		}
	}
	debug << "return -1";
	return -1;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%s", b[i]);
	string from = "", to = "";
	bool found = false;
	for (int i = 0; i < n; ++i) {
		diff[i] = make_pair(-1, -1);
		for (int k = 0; a[i][k]; ++k)
			if (a[i][k] != b[i][k]) {
				diff[i].second = k + 1;
				if (diff[i].first == -1)
					diff[i].first = k;
			}
		debug << arr(a, i) arr(b, i);
		same[i] = (diff[i] == make_pair(-1, -1));
		if (!same[i]) {
			string curr_f = string(a[i] + diff[i].first, a[i] + diff[i].second);
			string curr_t = string(b[i] + diff[i].first, b[i] + diff[i].second);
			debug << imie(curr_f) imie(curr_t);
			if (found) {
				if (from != curr_f || to != curr_t)
					err();
			}
			else {
				from = curr_f;
				to = curr_t;
			}
			found = true;
		}
	}
	while (true) {
		bool poss = true;
		char _a = -1, _b = -1;
		for (int i = 0; i < n; ++i)
			if (!same[i]) {
				if (diff[i].first == 0) {
					poss = false;
					break;
				}
				else if (_a == -1) {
					_a = a[i][diff[i].first - 1];
					_b = b[i][diff[i].first - 1];
				}
				else if (a[i][diff[i].first - 1] != _a || b[i][diff[i].first - 1] != _b) {
					poss = false;
					break;
				}
			}
		if (poss) {
			for (int i = 0; i < n; ++i)
				if (!same[i])
					diff[i].first--;
		}
		else
			break;
	}
	while (true) {
		bool poss = true;
		char _a = -1, _b = -1;
		for (int i = 0; i < n; ++i)
			if (!same[i]) {
				if (a[i][diff[i].second] == 0) {
					poss = false;
					break;
				}
				else if (_a == -1) {
					_a = a[i][diff[i].second];
					_b = b[i][diff[i].second];
				}
				else if (a[i][diff[i].second] != _a || b[i][diff[i].second] != _b) {
					poss = false;
					break;
				}
			}
		if (poss) {
			for (int i = 0; i < n; ++i)
				if (!same[i])
					diff[i].second++;
		}
		else
			break;
	}
	long long hash = 0;
	int len = 0;
	for (int i = 0; i < n; ++i)
		if (!same[i]) {
			debug << string(a[i] + diff[i].first, a[i] + diff[i].second);
			for (int k = diff[i].first; k < diff[i].second; ++k) {
				hash = (hash * B + a[i][k]) % M;
				powe = (powe * B) % M;
				len++;
			}
			break;
		}
	for (int i = 0; i < n; ++i) {
		int p = search(a[i], len, hash);
		debug << arr(a, i) imie(p) arr(diff, i);
		if (same[i]) {
			if (p != -1) err();
		}
		else {
			if (p != diff[i].first) err();
		}
	}
	for (int i = 0; i < n; ++i) {
		if (!same[i]) {
			printf("YES\n%s\n%s\n", string(a[i] + diff[i].first, a[i] + diff[i].second).c_str(), string(b[i] + diff[i].first, b[i] + diff[i].second).c_str());
			return 0;
		}
	}
}