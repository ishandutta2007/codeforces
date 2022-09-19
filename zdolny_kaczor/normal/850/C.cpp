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
const int MB = 30;
unordered_map <bitset <MB>, int> memo;
int nimber(bitset <MB> x) {
	if (memo.count(x))
		return memo[x];
	bitset <MB> seen;
	int last = 0;
	REP(i, MB)
		if (x[i])
			last = i;
	FOR(l, 1, last) {
		auto y = x;
		FOR(i, l, MB - 1)
			if (y[i]) {
				y[i] = false;
				y[i - l] = true;
			}
		debug << name(last) << "make " << y << "from " << x << endl;
		seen[nimber(y)] = true;
	}
	REP(i, MB)
		if (!seen[i]) {
			memo[x] = i;
			debug << "nimber " << x << " = " << i << endl;
			return i;
		}
	assert(false);
}
int main() {
	map <int, bitset<MB> > state;
	int n;
	scanf("%d", &n);
	REP(i, n) {
		int x;
		scanf("%d", &x);
		for (int p = 2; p * p <= x; ++p) {
			if (x % p == 0) {
				int e = 0;
				while (x % p == 0) {
					x /= p;
					e++;
				}
				state[p][e] = true;
			}
		}
		if (x > 1)
			state[x][1] = true;
	}
	int ans = 0;
	for (auto &c : state)
		ans ^= nimber(c.s);
	if (ans)
		printf("Mojtaba");
	else
		printf("Arpa");
}