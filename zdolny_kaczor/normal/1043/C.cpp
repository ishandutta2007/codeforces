# include <bits/stdc++.h>
using namespace std;
#define sim template <class t
#define dor > debug & operator<<(
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<t>(0)) r 1, debug&>::type operator<<(t h) {
sim> struct rge {t h, n;};
sim> rge<t> range(t h, t n) {return rge<t>{h, n};}
sim> auto dud(t *r) -> decltype(cerr << *r, 2);
sim> char dud(...);
struct debug {
#ifdef LOCAL
	~debug() {cerr << endl;}
	eni(!=) cerr << boolalpha << h; ris;}
	eni(==) ris << range(begin(h), end(h));}
	sim dor rge<t> u) {
		cerr << '{';
		for (t a = u.h; a!= u.n; ++a)
			*this << ", " + 2 * (a == u.h) << *a;
		ris << '}';
	}
	sim, class n dor pair <n,t> r) {ris << "<" << r.first << ", " << r.second << ">";}
	#else
	sim dor const t&) {ris;}
	#endif
};
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
const int MN = 1e3 + 44;
char in[MN];
int ans[MN];
int main() {
	scanf("%s", in);
	bool inverted = false;
	int n = strlen(in);
	for (int i = n - 1; i >= 1; --i) {
		debug << imie(i) imie(inverted);
		if (inverted) {
			if (in[i] == 'b') {
				ans[i] = 1;
				inverted = false;
			}
		}
		else {
			if (in[i] == 'a') {
				ans[i] = 1;
				inverted = true;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}