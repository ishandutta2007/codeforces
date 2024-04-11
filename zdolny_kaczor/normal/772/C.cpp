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
const int MN = 2e5 + 44;
map <int, set <int> > cou;
PII dp[MN];
int n, m;
int NWD;
PLL ext_gcd(LL a,LL b) {
	if (b==0) {
		NWD=a;
		return MP(1,0);
	}
	PLL ret;
	ret.f=ext_gcd(b,a%b).s;
	ret.s=(NWD-ret.f*a)/b;
	debug << "ext_gcd(" << name(a) << ", " << name(b) << ") = " << ret << endl;
	return ret;
}
#define div snathoelc
int div(int x, int y) { //x / y
	debug << "div " << name(x) << name(y) << endl;
	int k = __gcd(y, m);
	y /= k;
	assert(x % k == 0);
	x /= k;
	debug << "reach div " << name(x) << name(y) << endl;
	PLL o = ext_gcd(m / k, y);
	debug << name(o) << endl;
	int ret = (x * o.s % m + m) % m;
	debug << name(ret) << endl;
	return ret;
}
VI ans;
int go(int x) {
	debug << "go ( " << name(x) << " )" << endl;
	int curr = 1;
	if (x != 1)
		curr = go(dp[x].s);
	for (int y : cou[x]) {
		ans.PB(div(y, curr));
		curr = y;
	}
	return curr;
}
int main() {
	scanf("%d%d", &n, &m);
	REP(i, m)
		cou[__gcd(i, m)].insert(i);
	REP(i, n) {
		int x;
		scanf("%d", &x);
		cou[__gcd(x, m)].erase(x);
	}
	debug << name(cou) << endl;
	for (auto & x : cou) {
		for (auto & y : cou) {
			if (x.f % y.f == 0 && y.f != x.f) {
				debug << name(x) << name(y) << endl;
				debug << "maxi " << name(MP(dp[y.f].f, y.f)) << endl;
				maxi(dp[x.f], MP(dp[y.f].f, y.f));
			}
		}
		debug << arr(dp, x.f) << " += " << name(x.s.size()) << endl;
		dp[x.f].f += x.s.size();
		debug << arr(dp, x.f) << endl;
	}
	go(m);
	printf("%d\n", siz(ans));
	for (int x : ans)
		printf("%d ", x);
	printf("\n");
}