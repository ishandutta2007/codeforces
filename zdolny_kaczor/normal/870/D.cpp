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
#define arr(a, i) #a cc #i rr #a cc i rr a[i] << " "
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
const int MN = 1 << 14;
int a1[MN];
int eq[MN];
int query(int a, int b) {
	printf("\? %d %d\n", a, b);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
vector <int> p, b, ans;
int main() {
	int n;
	scanf("%d", &n);
	p.resize(MN);
	b.resize(MN);
	ans.resize(MN);
	REP(i, n)
		eq[i] = query(i, i);
	FOR(i, 1, n - 1)
		a1[i] = query(0, i);
	a1[0] = eq[0];
	int count = 0;
	REP(first, n) {
		debug2 << name(first) << endl;
		REP(i, n)
			p[i] = first ^ eq[i] ^ a1[i];
		REP(i, n)
			b[i] = first ^ a1[i];
		debug2 << name(p) << name(b) << endl;
		bool good = true;
		REP(i, n) {
			debug2 << arr(p, b[i]) << arr(b, i) << endl;
			if (p[b[i]] != i) {
				debug2 << false << endl;
				good = false;
			}
		}
		if (good) {
			count++;
			swap(ans, p);
		}
	}
	printf("!\n%d\n", count);
	ans.resize(n);
	for (int x : ans)
		printf("%d ", x);
	printf("\n");
}