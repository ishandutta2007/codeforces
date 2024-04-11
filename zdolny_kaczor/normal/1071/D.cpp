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
#define div __div__et2UE4
const int MN = 1e6 + 1, MP = 7;
int div[MN];
int seen[MN];
int primes[MP] = {2, 3, 5, 7, 11, 13, 17};
vector <vector <int> > fac;
int divs(const vector <int> & x) {
	int r = 1;
	for (int v : x)
		r *= v + 1;
	return r;
}
void gen(vector <int> curr, int val, int last) {
	fac.push_back(curr);
	if (curr.size() == MP) return;
	for (int i = 1; i <= last; ++i) {
		if (val * 1ll * primes[curr.size()] > 1e9)
			break;
		val *= primes[curr.size()];
		vector <int> next = curr;
		next.push_back(i);
		gen(next, val, i);
	}
}
vector <vector <int> > graf;
const int DIFF = 257;
const int MF = 1300;
int dist[MF][DIFF];
int d[MF];
sim> void maxi(t &x, t y) {
	if (x < y) x = y;
}
sim> void mini(t &x, t y) {
	if (x > y) x = y;
}
void bfs() {
	for (int start = 0; start < (int)fac.size(); ++start) {
		for (int i = 0; i < (int)fac.size(); ++i)
			d[i] = 1e9;
		d[start] = 0;
		queue<int> kol;
		kol.push(start);
		while (!kol.empty()) {
			int c = kol.front();
			kol.pop();
			for (int x : graf[c]) {
				if (d[x] > d[c] + 1) {
					d[x] = d[c] + 1;
					kol.push(x);
				}
			}
		}
		for (int i = 0; i < DIFF; ++i)
			dist[start][i] = 1e9;
		for (int i = 0; i < (int)fac.size(); ++i)
			mini(dist[start][seen[divs(fac[i])]], d[i]);
	}
}
void make_edge(int i, const vector <int> & a) {
	debug << arr(fac, i) << imie(a);
	int l = 0, r = fac.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (fac[m] == a) {
			graf[i].push_back(m);
			return;
		}
		else if (fac[m] < a)
			l = m + 1;
		else
			r = m - 1;
	}
}
void make_graph() {
	graf.resize(fac.size());
	for (int num = 0; num < (int)fac.size(); ++num) {
		vector <int> x = fac[num];
		int l = x.size();
		for (int i = 0; i < l; ++i) {
			if (i == 0 || x[i - 1] > x[i]) {
				x[i]++;
				make_edge(num, x);
				x[i]--;
			}
			if (i == l - 1 || x[i + 1] < x[i])  {
				x[i]--;
				bool zero = (x[i] == 0);
				if (zero)
					x.pop_back();
				make_edge(num, x);
				if (zero)
					x.push_back(0);
				x[i]++;
			}
		}
		x.push_back(1);
		make_edge(num, x);
	}
}
int find(const vector <int>  &x) {
	int l = 0, r = fac.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (fac[m] == x) return m;
		else if (fac[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	debug << imie(x);
	assert(false);
}
vector <int> factor(int x) {
	vector <int> ans;
	while (x > 1) {
		int p = div[x], e = 0;
		while (x % p == 0) {
			x /= p;
			e++;
		}
		ans.push_back(e);
	}
	sort(ans.rbegin(), ans.rend());
	return ans;
}
int main() {
	for (int i = 2; i < MN; ++i)
		if (div[i] == 0) {
			for (int x = i; x < MN; x += i)
				div[x] = i;
		}
	gen(vector <int>(), 1, 20);
	for (int i = 0; i < MN; ++i)
		seen[i] = -1;
	int cou = 0;
	for (auto & x : fac) {
		int d = divs(x);
		if (seen[d] == -1)
			seen[d] = cou++;
	}
	sort(fac.begin(), fac.end());
	make_graph();
	bfs();
	debug << imie(fac) << fac.size() << imie(cou);
	int q;
	scanf("%d", &q);
	for (int _ = 0; _ < q; ++_) {
		int a, b;
		scanf("%d%d", &a, &b);
		vector <int> fa = factor(a), fb = factor(b);
		int na = find(fa), nb = find(fb);
		int ans = 1e9;
		for (int i = 0; i < cou; ++i)
			mini(ans, dist[na][i] + dist[nb][i]);
		printf("%d\n", ans);
	}
}