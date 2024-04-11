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
const int MN = 3e5 + 44;
int cou[MN];
int muls[MN];
#define div __Div__1qRE3_
int div[MN];
int divs[MN];
int square_free(int x) {
	int ans = 1;
	debug << imie(x);
	while (x > 1) {
		int p = div[x];
		ans *= p;
		while (x % p == 0)
			x /= p;
	}
	debug << imie(ans);
	return ans;
}
sim> void mini(t &x, t y) {
	if (x > y) x = y;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i < MN; ++i)
		if (div[i] == 0)
			for (int k = i; k < MN; k += i)
				div[k] = i;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		cou[square_free(x)] = 1;
	}
	for (int i = 1; i < MN; ++i)
		for (int k = i; k < MN; k += i) {
			muls[i] += cou[k];
			divs[k] += cou[i];
		}
	int ans = 1e9;
	for (int i = 0; i < MN; ++i)
		if (cou[i] && divs[i] == 1) {
			vector <int> primes;
			int x = i;
			while (x > 1) {
				int p = div[x];
				primes.push_back(p);
				while (x % p == 0)
					x /= p;
			}
			int seen[1 << 6] = {};
			int pro[1 << 6] = {};
			int divs = primes.size();
			pro[0] = 1;
			seen[0] = muls[1];
			debug << imie(i) imie(primes);
			for (int m = 1; m < (1 << divs); ++m) {
				int i = __builtin_ctz(m);
				pro[m] = pro[m ^ (1 << i)] * primes[i];
				seen[m] = muls[pro[m]];
			}
			debug << "before: " << range(seen, seen + (1 << divs));
			for (int i = 0; i < divs; ++i)
				for (int m = 1 << i; m < (1 << divs);)
					if (m >> i & 1) {
						seen[m ^ (1 << i)] -= seen[m];
						m++;
					}
					else
						m |= (1 << i);
			for (int i = 0; i < divs; ++i)
				for (int m = 1 << i; m < (1 << divs);) {
					if (m >> i & 1) {
						seen[m] |= seen[m ^ (1 << i)];
						m++;
					}
					else
						m |= (1 << i);
				}
			debug << "after: " << range(seen, seen + (1 << divs));
			int dist[1 << 6] = {};
			for (int i = (1 << divs) - 1; i >= 0; --i)
				dist[i] = 1e9;
			dist[(1 << divs) - 1] = 0;
			const int all = (1 << divs) - 1;
			for (int i = (1 << divs) - 1; i >= 0; --i)
				for (int m = i; ; m = (m - 1) & i) {
					if (seen[all ^ m])
						mini(dist[i ^ m], dist[i] + 1);
					if (m == 0)
						break;
				}
			mini(ans, dist[0] + 1);
		}
	if (ans > n)
		printf("-1\n");
	else
		printf("%d\n", ans);
}