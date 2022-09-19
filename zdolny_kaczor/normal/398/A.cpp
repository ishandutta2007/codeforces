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
using ll = long long;
ll min_score(int cards, int groups) {
	return cards % groups * (cards / groups + 1ll) * (cards / groups + 1ll) +
		(groups - cards % groups) * (cards / groups * 1ll) * (cards / groups * 1ll);
}
ll max_score(int cards, int groups) {
	return groups - 1 + (cards - groups + 1) * 1ll * (cards - groups + 1);
}
void show(char c, int i) {
	for (int _ = 0; _ < i; ++_)
		putchar(c);
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	pair <ll, int> ans = make_pair((ll)-1e18, 0);
	if (a == 0) {
		printf("%lld\n", -b * 1ll * b);
		for (int i = 0; i < b; ++i) putchar('x');
		printf("\n");
		return 0;
	}
	if (b == 0) {
		printf("%lld\n", a * 1ll * a);
		for (int i = 0; i < a; ++i) putchar('o');
		printf("\n");
		return 0;
	}
	for (int g = 1; g <= a; ++g)
		ans = max(ans, make_pair(max_score(a, g) - min_score(b, g + 1), g));
	int g = ans.second;
	vector <int> xes(g + 1), oes(g);
	printf("%lld\n", ans.first);
	for (int i = 0; i < b; ++i)
		xes[i % (g + 1)]++;
	for (int i = 0; i < a; ++i)
		oes[min(i, g - 1)]++;
	for (int i = 0; i < g; ++i) {
		show('x', xes[i]);
		show('o', oes[i]);
	}
	show('x', xes.back());
	printf("\n");
	debug << imie(xes) imie(oes);
}