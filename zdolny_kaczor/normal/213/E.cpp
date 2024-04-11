#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug cerr << "[LINE:" << __LINE__ << "] " << boolalpha
#else
#define debug if(0) cout
#endif
#define fs(r) r.f, r.s
template <typename T, typename C>
ostream & operator<<(ostream &os, pair<T, C> x) {
	return os << "<" << x.f << ", " << x.s << ">";
}
template <typename T>
auto operator<<(ostream&os, T x) -> typename enable_if<is_same<decltype(x.begin()), decltype(x.end())>::value && !is_same<T, string>::value, ostream &>::type {
	os << "{";
	int cou = 0;
	for (auto c : x) {
		if (cou++)
			os << ", ";
		os << c;
	}
	return os << "}";
}
#define cr << "][" << 
#define rr << "] = " << 
#define cc << "[" <<
#define ao << ' ' 
#define name(a) #a << " = " << (a) ao
#define arr(a, i) #a cc #i rr #a cc i rr a[i] ao
#define arr2(a, i, j) #a cc #i cr #j rr #a cc i cr j rr a[i][j] ao
#define arr3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc i cr j cr k rr a[i][j][k] ao
#define arr4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc i cr j cr k cr q rr a[i][j][k][q] ao
template <typename T>
string strmask(T r) {
	string ans;
	REP(i, 8 * (int)sizeof(T)) {
		ans += '0' + !!(((T)1 << i) & r);
		if (i % 5 == 4)
			ans += '.';
	}
	return ans;
}
#if 0 
ostream & operator<< (ostream & os, __int128_t x) {
	if (x < 0) {
		os << '-';
		x = -x;
	}
	if (x >= 10)
		os << x / 10;
	return os << (int)x % 10;
}
ostream & operator<< (ostream & os, __uint128_t x) {
	if (x >= 10)
		os << x / 10;
	return os << (int)x % 10;
}
#endif
#define nmask(a) #a << " = " << strmask(a) ao
const int SIZE = 1 << 18;
PLL tree[SIZE * 2];
const PLL empty = MP(1, 0);
const int mod = 1998917923;
const int base = 10000007;
PLL make(int x) {
	return MP(base, x);
}
PLL merge(PLL x, PLL y) {
	return MP(x.f * y.f % mod, (x.s * y.f + y.s) % mod);
}
int inv[SIZE];
void edit(int pos, PLL val) {
	debug << "edit " << name(pos) << name(val) << endl;
	pos += SIZE;
	tree[pos] = val;
	pos /= 2;
	while (pos) {
		tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
		pos /= 2;
	}
}
int main() {
	REP(i, SIZE * 2)
		tree[i] = empty;
	int n, m;
	scanf("%d%d", &n, &m);
	assert(merge(merge(make(1), make(7)), make(9)) == merge(make(1), merge(make(7), make(9))));
	assert(merge(make(1), make(2)) != merge(make(2), make(1)));
	PLL hash = empty;
	LL pow = 1;
	REP(i, SIZE) {
		pow = pow * base % mod;
		assert(pow != 1);
	}
	REP(i, n) {
		int x;
		scanf("%d", &x);
		hash = merge(hash, make(x));
	}
	FOR(i, 1, m) {
		int x;
		scanf("%d", &x);
		inv[x] = i;
	}
	PLL ones = empty;
	REP(i, n)
		ones = merge(ones, make(1));
	FOR(i, 1, n)
		edit(inv[i], make(i));
	int ans = 0;
	FOR(i, 1, m - n + 1) {
		debug << name(tree[1]) << endl;
		if ((tree[1].s - hash.s - ones.s * (i - 1)) % mod == 0) {
			debug << "found " << name(i) << endl;
			ans++;
		}
		edit(inv[i], empty);
		edit(inv[i + n], make(i + n));
	}
	printf("%d\n", ans);
}