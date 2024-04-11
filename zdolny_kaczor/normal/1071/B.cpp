# include <bits/stdc++.h>
using namespace std;
#define FORBITS(i,m)  for(decltype(m)lP6N4Slr=(m),i=lP6N4Slr?ctz(lP6N4Slr):0;lP6N4Slr;lP6N4Slr^=((decltype(m))1<<i),i=ctz(lP6N4Slr))
#define FORDBITS(i,m) for(decltype(m)_6Im=(m),i=_6Im?8*sizeof(m)-clz(_6Im)-1:0;_6Im;_6Im^=((decltype(m))1<<i),i=8*sizeof(m)-clz(_6Im)-1)
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
const int MN = 1 << 11;
char in[MN][MN];
int dp[MN][MN];
int n, k;
sim> void maxi(t &x, t y) {
	if (x < y) x = y;
}
sim> void mini(t &x, t y) {
	if (x > y) x = y;
}
void fill() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			dp[i][j] = 0;
			if (i)
				maxi(dp[i][j], dp[i - 1][j]);
			if (j)
				maxi(dp[i][j], dp[i][j - 1]);
			dp[i][j] += (in[i][j] == 'a');
		}
}
int hashi[MN][MN];
int main() {
	scanf("%d%d", &n, &k);
	if (k >= 2 * n - 1) {
		for (int i = 0; i < 2 * n - 1; ++i)
			putchar('a');
		printf("\n");
		return 0;
	}
	k = min(k, 2 * n - 1);
	for (int i = 0; i < n; ++i)
		scanf("%s", in[i]);
	fill();
	for (int i = 0; i < n; ++i)
		debug << imie(i) << range(dp[i], dp[i] + n);
	int as = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i + j + 1 - dp[i][j] <= k)
				maxi(as, i + j + 1);
	debug << imie(as);
	if (as == 2 * n - 1) {
		for (int i = 0; i < 2 * n - 1; ++i)
			putchar('a');
		printf("\n");
		return 0;
	}
	hashi[n - 1][n - 1] = 0;
	for (int sum = 2 * n - 3; sum >= 0; --sum) {
		map <int, vector <pair <int, int> > > seen;
		for (int i = 0; i < n; ++i) {
			int j = sum - i;
			if (j < 0 || j >= n)
				continue;
			int suf_hash = 1e9;
			if (i < n - 1)
				mini(suf_hash, hashi[i + 1][j]);
			if (j < n - 1)
				mini(suf_hash, hashi[i][j + 1]);
			debug << imie(i) imie(j) imie(suf_hash);
			int my_hash = in[i][j] * 1000000 + suf_hash;
			seen[my_hash].emplace_back(i, j);
		}
		debug << imie(seen);
		int cou = 0;
		for (auto & x : seen) {
			for (pair <int, int> y : x.second)
				hashi[y.first][y.second] = cou;
			cou++;
		}
	}
	for (int i = 0; i < n; ++i)
		debug << imie(i) << range(hashi[i], hashi[i] + n);
	pair <int, pair <int, int> > start;
	start.first = 1e9;
	for (int i = 0; i < n; ++i) {
		int j = as - i - 1;
		if (j < 0 || j >= n)
			continue;
		if (i + j + 1 - dp[i][j] <= k) {
			debug << imie(i) imie(j);
			if (i != n - 1)
				mini(start, make_pair(hashi[i + 1][j], make_pair(i + 1, j)));
			if (j != n - 1)
				mini(start, make_pair(hashi[i][j + 1], make_pair(i, j + 1)));
		}
	}
	string ans(as, 'a');
	ans.push_back(in[start.second.first][start.second.second]);
	pair <int, int> pos = start.second;
	while (pos != make_pair(n - 1, n - 1)) {
		if (pos.second == n - 1)
			pos.first++;
		else if (pos.first == n - 1)
			pos.second++;
		else {
			if (hashi[pos.first + 1][pos.second] < hashi[pos.first][pos.second + 1])
				pos.first++;
			else
				pos.second++;
		}
		ans.push_back(in[pos.first][pos.second]);
	}
	printf("%s\n", ans.c_str());
}