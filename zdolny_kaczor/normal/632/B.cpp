//Maciej Houbowicz
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
const int MN = 5e5 + 44;
int a[MN];
char whose[MN];
int main() {
	int n;
	scanf("%d", &n);
	LL sum = 0;
	REP(i, n) {
		scanf("%d", a + i);
		sum += a[i];
	}
	scanf("%s", whose);
	LL diff = 0;
	REP(i, n) {
		if (whose[i] == 'B')
			diff += a[i];
		else
			diff -= a[i];
	}
	LL maxdiff = abs(diff);
	LL currdiff = diff;
	REP(i, n) {
		if (whose[i] == 'B')
			currdiff -= 2 * a[i];
		else
			currdiff += 2 * a[i];
		maxi(maxdiff, abs(currdiff));
	}
	printf("%lld\n", (sum + maxdiff) / 2);
}