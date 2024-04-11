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
const int MN = 1e6 + 44;
char in[MN];
int l[MN], r[MN];
int pre(int x) {
	if (l[x] == x) return x;
	else return l[x] = pre(l[x]);
}
int nex(int x) {
	if (r[x] == x) return x;
	else return r[x] = nex(r[x]);
}
void rem(int x) {
	r[x] = x + 1;
	l[x] = x - 1;
}
vector <int> swaps[2];
void tryins(VI & v, int x) {
	if (v.empty() || v.back() < x)
		v.PB(x);
}
int main() {
	scanf("%s", in + 1);
	int n = strlen(in + 1);
	REP(i, n + 2)
		l[i] = r[i] = i;
	FOR(i, 1, n) {
		if ((i != 1 && in[i - 1] != in[i]) || (i != n && in[i] != in[i + 1]))
			swaps[0].PB(i);
	}
	int ans = 0;
	while (!swaps[0].empty()) {
		debug << name(swaps[0]) << endl;
		ans++;
		for (int x : swaps[0])
			rem(x);
		for (int x : swaps[0]) {
			int pr = pre(x), ne = nex(x);
			debug << name(x) << name(pr) << name(ne) << endl;
			if (pr != 0 && ne != n + 1 && in[pr] != in[ne]) {
				debug << "different " << endl;
				tryins(swaps[1], pr);
				tryins(swaps[1], ne);
			}
		}
		swap(swaps[0], swaps[1]);
		swaps[1].clear();
	}
	printf("%d\n", ans);
}