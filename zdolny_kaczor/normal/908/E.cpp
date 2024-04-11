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
#define count __coustoe
const int MN = 50, MM = 1010, mod = 1e9 + 7;
unordered_map <bitset<MN>, int> count;
bitset <MN> in[MM];
char str[MM];
LL binom[MM][MM];
LL spl[MM];
int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	REP(i, n) {
		scanf("%s", str);
		REP(j, m)
			if (str[j] == '1')
				in[j][i] = 1;
	}
	REP(i, m)
		count[in[i]]++;
	LL ans = 1;
	binom[0][0] = 1;
	FOR(i, 1, MM - 1) {
		binom[i][0] = binom[i][i] = 1;
		FOR(j, 1, i - 1)
			binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
	}
	debug << arr2(binom, 10, 5) << arr2(binom, 1000, 5) << arr2(binom, 1001, 666) << endl;
	spl[0] = 1;
	FOR(i, 1, MM - 1) {
		FOR(c, 0, i - 1)
			spl[i] = (spl[i] + binom[i - 1][c] * spl[i - c - 1]) % mod;
	}
	REP(i, 20)
		debug << arr(spl, i) << endl;
	for (auto & x : count)
		ans = ans * spl[x.s] % mod;
	debug << name(count) << endl;
	printf("%lld\n", (ans % mod + mod) % mod);

}