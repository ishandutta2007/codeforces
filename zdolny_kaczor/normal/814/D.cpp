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
#define ope(a, b, c) #a << #b << #c << " = " << a << #b << c << " = " << (a b c)
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
const int MN = 1e3 + 44;
pair <PII, int> in[MN];
LL dist(PII a, PII b) {
	return (a.f - b.f) * 1ll * (a.f - b.f) + (a.s - b.s) * 1ll * (a.s - b.s);
}
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		scanf("%d%d%d", &in[i].f.f, &in[i].f.s, &in[i].s);
	}
	LL ans = 0;
	REP(i, n) {
		int ins = 0;
		REP(k, n) if (in[k].s > in[i].s) {
			if (dist(in[i].f, in[k].f) < in[k].s * 1ll * in[k].s) {
				ins++;
			}
		}
		LL curr = in[i].s * 1ll * in[i].s;
		debug2 << arr(in, i) << ' ' << name(ins) << ' ' << name(curr) << endl;
		if (ins % 2 || ins == 0)
			ans += curr;
		else
			ans -= curr;
	}
	debug2 << name(ans) << endl;
	printf("%.11Lf\n", (LD)(ans * 3.141592653589793238462643383279502884L));
}