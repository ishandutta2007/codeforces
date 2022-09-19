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
#define name(a) #a << " = " << (a)
#define arr(a, i) #a cc #i rr #a cc i rr a[i]
#define arr2(a, i, j) #a cc #i cr #j rr #a cc i cr j rr a[i][j]
#define arr3(a, i, j, k) #a cc #i cr #j cr #k rr #a cc i cr j cr k rr a[i][j][k]
#define arr4(a, i, j, k, q) #a cc #i cr #j cr #k cr #q rr #a cc i cr j cr k cr q rr a[i][j][k][q]
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
const int MN = 1e6 + 44;
LL fac[MN];
LL fin[MN];
#define pow santoherstn
LL pow(LL b, int e) {
	if (e == 0) return 1;
	if (e % 2) return pow(b, e - 1) * b % mod;
	return pow(b * b % mod, e / 2);
}
LL inv[MN];
const int A = 26;
LL smaller(char a[MN], char b[MN]) {
	int n = strlen(a);
	static int count[A];
	REP(i, 26)
		count[i] = 0;
	LL finpro = 1;
	REP(i, n)
		count[a[i] - 'a']++;
	REP(i, 26)
		finpro = finpro * fin[count[i]] % mod;
	LL ans = 0;
	REP(i, n) {
		REP(l, b[i] - 'a')
			ans += fac[n - i - 1] * finpro % mod * (count[l]);
		debug2 << arr(fac, n - i - 1) << ' ' << name(finpro) << endl;;
		ans %= mod;
		if (count[b[i] - 'a'] == 0)
			break;
		finpro *= count[b[i] - 'a'];
		finpro %= mod;
		count[b[i] - 'a']--;
	}
	return ans;
}
char a[MN], b[MN];
int main() {
	fac[0] = 1;
	FOR(i, 1, MN - 1)
		fac[i] = fac[i - 1] * i % mod;
	fin[MN - 1] = pow(fac[MN - 1], mod - 2);
	FORD(i, MN - 2, 0)
		fin[i] = fin[i + 1] * (i + 1) % mod;
	FOR(i, 1, MN - 1)
		inv[i] = fac[i - 1] * inv[i] % mod;
	scanf("%s%s", a, b);
	int n = strlen(a);
	LL ans = (smaller(a, b) - smaller(a, a) - 1) % mod;
	if (ans < 0)
		ans += mod;
	printf("%lld\n", ans);
}