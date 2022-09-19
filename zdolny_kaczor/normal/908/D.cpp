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
const bool deb = true;
#else
#define debug if(0) cout
const bool deb = false;
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
const int MN = deb ? 700 : 2010;
const int mod = 1e9 + 7;
#define rea pair <LL, LD>
rea dp[MN][MN][2];
rea apr, bpr;
#define pow snatoheulcar
LL pow(LL b, int e) {
	if (e == 0) return 1;
	if (e % 2) return pow(b, e - 1) * b % mod;
	return pow(b * b % mod, e / 2);
}
rea operator+(rea a, rea b) {
	return MP((a.f + b.f) % mod, a.s + b.s);
}
rea operator*(rea a, rea b) {
	return MP((a.f * b.f) % mod, a.s * b.s);
}
rea make(int x) {
	return MP((LL)x, (LD)x);
}
rea operator/ (rea a, rea b) {
	return MP(a.f * pow(b.f, mod - 2) % mod, a.s / b.s);
}
rea operator-(rea a, rea b) {
	return MP((a.f - b.f + mod) % mod, a.s - b.s);
}
rea rpow(rea a, int b) {
	if (b == 0)
		return make(1);
	if (b % 2)
		return rpow(a, b - 1) * a;
	return rpow(a * a, b / 2);
}
int main() {
	int k, pa, pb;
	scanf("%d%d%d", &k, &pa, &pb);
	apr = make(pa) / make(pa + pb);
	bpr = make(pb) / make(pa + pb);
	debug << name(apr) << name(bpr) << endl;
	dp[1][0][0] = make(1);
	FOR(a, 1, MN - 1) {
		FOR(pai, 0, MN - 1) {
			rea total = dp[a][pai][0] + dp[a][pai][1];
			if (a + 1 < MN)
				dp[a + 1][pai][0] = total * apr;
			if (a + pai < MN)
				dp[a][a + pai][1] = total * bpr;
		}
	}
	rea ans = make(0);
	FOR(a, 1, MN - 1)
		REP(pairs, k) {
			if (a == MN - 1) {
				debug << arr3(dp, a, pairs, 0) << endl;
				debug << name(make(1) / apr) << endl;
				debug << name(make(a) + make(1) / bpr + make(pairs) - make(1)) << endl;
				debug << "ans += " << dp[a][pairs][0] * (make(a) + make(1) / bpr + make(pairs) - make(1)) << endl;
				ans = ans + dp[a][pairs][0] * (make(a) + make(1) / bpr + make(pairs) - make(1));
			}
			else {

				int left = (k - pairs + a - 1) / a;
				debug << name(a) << name(pairs) << name(left) << endl;
				debug << arr3(dp, a, pairs, 0) <<
					name(make(pairs + left * a) ) <<
					name(rpow(bpr, left)) << endl;
				debug << "ans += " << dp[a][pairs][0] * make(pairs + left * a) * rpow(bpr, left) << endl;
				ans = ans + dp[a][pairs][0] * make(pairs + left * a) * rpow(bpr, left);
			}
		}
	REP(a, 3)
		REP(pai, 7)
			debug << arr3(dp, a, pai, 0) << arr3(dp, a, pai, 1) << endl;
	debug << name(ans) << endl;
	printf("%lld\n", (ans.f + mod) % mod);
}