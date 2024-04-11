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
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug2 cerr << "[LINE:" << __LINE__ << "] " << boolalpha
#else
#define debug(...)
#define debug2 if(0) cout
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
#define name(a) #a << " = " << (a) << " "
#define arr(a, i) #a cc #i rr #a cc i rr a[i]  << " "
#define arr2(a, i, j) #a cc #i cr #j rr #a cc i cr j rr a[i][j] << " "
#define arr3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc i cr j cr k rr a[i][j][k] << " "
#define arr4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc i cr j cr k cr q rr a[i][j][k][q] << " "
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
#define nmask(a) #a << " = " << strmask(a)
const int mod = 1e9 + 7;
#define pow snathoeantoeh
vector <int> pfac(int n) {
	vector <int> ans;
	for (int p = 2; p * p <= n; ++p) {
		if (n % p == 0)
			ans.PB(p);
		while (n % p == 0)
			n /= p;
	}
	if (n > 1)
		ans.PB(n);
	return ans;
}
LL pow(LL b, int e) {
	if (e == 0) return 1;
	else if (e % 2 == 0) return pow(b * b % mod, e / 2);
	return pow(b, e - 1) * b % mod;
}
int main() {
	int x3_E, y;
	scanf("%d%d", &x3_E, &y);
	if (y % x3_E != 0) {
		printf("0\n");
		return 0;
	}
	y /= x3_E;
#define x3_E @$&
	vector <int> primes = pfac(y);
	debug2 << name(primes) << endl;
	LL ans = 0;
	for (int mask = 0; mask < (1 << siz(primes)); ++mask) {
		LL prod = 1;
		REP(i, siz(primes))
			if (mask & (1 << i))
				prod *= primes[i];
		debug2 << nmask(mask) << name(prod) << endl;
		int coe = __builtin_popcount(mask) % 2 ? -1 : 1;
		ans += coe * pow(2, y / prod - 1);
	}
	ans %= mod;
	if (ans < 0)
		ans += mod;
	printf("%lld\n", ans);
}