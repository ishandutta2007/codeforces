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
VPII dirs = {MP(0, -1), MP(1, 0), MP(0, 1), MP(-1, 0)};
PII operator+ (PII a, PII b) {
	return MP(a.f + fs(b) + a.s);
}
const int MN = 55;
char maze[MN][MN];
char path[MN * 2];
char get(PII a) {
	return maze[a.f][a.s];
}
int main() {
	sort(ALL(dirs));
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 1, n)
		scanf("%s", maze[i] + 1);
	PII start = MP(-1, -1);
	FOR(i, 1, n)
		FOR(j, 1, m)
			if (maze[i][j] == 'S')
				start = MP(i, j);
	assert(start != MP(-1, -1));
	scanf("%s", path);
	int ans = 0;
	do {
		PII pos = start;
		bool found = false;
		for (int i = 0; path[i]; ++i) {
			pos = pos + dirs[path[i] - '0'];
			if (get(pos) == 'E') {
				found = true;
				break;
			}
			if (get(pos) != 'S' && get(pos) != '.')
				break;
		}
		if (found) {
			debug << name(dirs) << endl;
			ans++;
		}
	}
	while (next_permutation(ALL(dirs)));
	printf("%d\n", ans);
}