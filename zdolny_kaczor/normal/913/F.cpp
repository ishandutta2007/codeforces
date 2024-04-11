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
const bool deb = 
#ifdef DEB
true;
#define debug cerr << "[LINE:" << __LINE__ << "] " << boolalpha
#else
false;
#define debug if(0) cout
#endif
#define fs(r) r.f, r.s
#define ei else if
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
	return os << "}_" << x.size();
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
#define _2arr(a, b, i) #a cc #b cc #i << "]" rr #a cc #b cc i << "]" rr #a cc b[i] rr a[b[i]] ao
#define _3arr(a, b, c, i) #a cc #b cc #c cc #i << "]]" rr #a cc #b cc #c cc i << "]]" rr #a cc #b cc c[i] << "]" rr  #a cc b[c[i]] rr a[b[c[i]]] ao
#define range(a, i, j) #a cc i << ".." << j rr vector <remove_reference<decltype(a[0])>::type>(&a[i], &a[j + 1]) ao
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
const int mod = 998244353;
#define pow snatheonta
struct rea {
	LL f;
	rea (LL _ = 0) : f(_){}
};
const int MN = 2010;
LL pow(LL b, int e) {
	if (e == 0) return 1;
	if (e & 1) return pow(b, e - 1) * b % mod;
	return pow(b * b % mod, e / 2);
}
rea make();
rea operator+(rea a, rea b) {
				         return rea((a.f + b.f) % mod);
 }
 rea operator*(rea a, rea b) {
				         return rea((a.f * b.f) % mod);
 }
 rea make(int x) {
				         return rea(x);
 }
 rea operator/ (rea a, rea b) {
				         return rea(a.f * pow(b.f, mod - 2) % mod);
 }
 rea operator-(rea a, rea b) {
				         return rea((a.f - b.f + mod) % mod);
 }
 rea rpow(rea a, int b) {
				         if (b == 0)
												                 return make(1);
																				         if (b % 2)
																												                 return rpow(a, b - 1) * a;
																																				         return rpow(a * a, b / 2);
 }
 rea dp[MN];
 rea pra_best[MN][MN];
 rea p;
 rea psum[MN][MN];
int pairs(int x) {
	return x * (x - 1) / 2;
}
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	p = make(a) / make(b);
	dp[1] = make(0);
	psum[0][0] = make(1);
	pra_best[1][1] = make(1);
	FOR(size, 1, n) {
		FOR(subset, 0, size) {
			if (subset != 0)
				psum[size][subset] = psum[size][subset] + psum[size - 1][subset - 1] * rpow(make(1) - p, size - subset);
			if (subset != size)
				psum[size][subset] = psum[size][subset] + psum[size - 1][subset] * rpow(p, subset);
		}
	}
	dp[1] = make(0);
	FOR(i, 2, n) {
		rea rest = make(1);
		FOR(siz, 1, i - 1) {
			pra_best[i][siz] = pra_best[siz][siz] * psum[i][siz];
			rest = rest - pra_best[i][siz];
		}
		pra_best[i][i] = rest;
	}
	FOR(siz, 2, n) {
		dp[siz] = make(siz * (siz - 1) / 2) * make(1) / (make(1) - pra_best[siz][siz]);
		rea stay = make(1) - pra_best[siz][siz];
		FOR(sub, 1, siz - 1) {
			dp[siz] = dp[siz] + pra_best[siz][sub] / stay * (dp[sub] + dp[siz - sub] - make(pairs(siz - sub)));
		}
	}
	printf("%lld\n", dp[n].f);
}