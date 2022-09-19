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
char in[7];
int fac(int x) {
	if (x == 0) return 1;
	else return x * fac(x - 1);
}
VI extract(const map <char, int> x) {
	VI ans;
	for (auto y : x)
		ans.PB(y.s);
	return ans;
}
int orders(const VI & nums) {
	sort(in, in + 6);
	int ans = 0;
	bool first = true;
	do {
		bool match = true;
		int left = 0, pos = 0;
		REP(i, 6) {
			if (left == 0)
				left = nums[pos++] - 1;
			else {
				if (in[i] != in[i - 1])
					match = false;
				left--;
			}
		}
		if (match)
			ans++;
		first = false;
	}
	while (next_permutation(in, in + 6));
	debug << "orders(" << nums << " = ans" << endl;
	return ans;
}
int main() {
	scanf("%s", in);
	int ans = orders({1, 1, 1, 1, 1, 1}) + //identity
		6 * orders({1, 1, 4}) + //rotation by 90 axis passing through centers of opposite faces
		3 * orders({1, 1, 2, 2}) + //rotation by 180 axis passing through centers of opposite faces
		8 * orders({3, 3}) + //rotation by 120 by axis passing through opposite vertices
		6 * orders({2, 2, 2}); //rotation by 180 by axis passing through centers of opposite edges
	assert(ans % 24 == 0);
	printf("%d\n", ans / 24);
}