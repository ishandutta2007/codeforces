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
const int MN = 22;
int a[MN];
int b[MN];
int n;
bool fine() {
	map <long long, int> h1;
	map <long long, int> h2;
	int half1 = n / 2;
	int half2 = n - half1;
	REP(mask, 1 << half1) {
		long long s = 0;
		REP(i, half1) if (mask & (1 << i))
			s += a[i] - b[i];
		h1[s]++;
	}
	REP(mask, 1 << half2) {
		long long s = 0;
		REP(i, half2) if (mask & (1 << i))
			s += b[half1 + i] - a[half1 + i];
		h2[s]++;
	}
	long long cou = 0;
	for (auto c : h1)
		cou += (LL) c.second * h2[c.first];
	return cou == 2;
}
PII ord[MN];
int main() {
	srand(time(NULL));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		ord[i] = MP(a[i], i);
	}
	sort(ord, ord + n);
	REP(i, n) {
		b[ord[i].s] = ord[(i + 1) % n].f;
	}
	REP(i, n)
		printf("%d ", b[i]);
	printf("\n");
}