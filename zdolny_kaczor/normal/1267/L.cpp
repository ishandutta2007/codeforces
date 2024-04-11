#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim>typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair <m,c>r){ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c&){ris;}
	#endif
};
#define debug muu() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r...) "[" #r ": " << (r) << "] "
#define range(a, b) "[[" #a ", " #b "): " << range(a, b) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
using pii = pair <int, int>;
using ll = long long;
const int nax = 1e6 + 44, lax = 1e3 + 44, A = 26;
char word[nax];
int ile[A];
char ans[lax][lax];
int main() {
	int n, k, l;
	scanf("%d%d%d", &n, &l, &k);
	scanf("%s", word);
	sort(word, word + n * l);
	int pos = 0;
	int start = 0;
	for (int i = 0; i < l; ++i) {
		for (int j = start; j < k; ++j) {
			ans[j][i] = word[pos++];
		}
		for (int j = start; j < k - 1; ++j) if (ans[j][i] != ans[j + 1][i]) start = j + 1;
	}
	for (int i = 0; i < l; ++i)
		for (int j = 0; j < n; ++j) if (ans[j][i] == 0) ans[j][i] = word[pos++];
	for (int i = 0; i < n; ++i) printf("%s\n", ans[i]);
}