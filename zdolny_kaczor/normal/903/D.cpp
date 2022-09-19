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
#define nmask(a) #a << " = " << strmask(a) ao
const int MN = 2e5 + 44;
vector <LL> sum;
int a[MN];
string parse(vector <LL> x, int len) {
	string ans = "";
	REP(_, len) {
		debug << name(x) << endl;
		LL mod = 0;
		for (LL &c : x) {
			int rem = c % 10;
			if (rem < 0)
				rem += 10;
			mod += rem;
			debug << "add " << name(mod) << endl;
			c -= rem;
			c /= 10;
		}
		ans = string(1, '0' + mod % 10) + ans;
		x.PB(mod / 10);
		debug << name(ans) << endl;
	}
	return ans;
}
string crop(string x) {
	string ans;
	bool seen = false;
	for (char c : x) {
		if (c != '0')
			seen = true;
		if (seen)
			ans.PB(c);
	}
	if (ans == "")
		ans = "0";
	return ans;
}
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", a + i);
	map <int, int> cou;
	REP(i, n) {
		sum.PB(a[i] * (2 * i - (n - 1ll)));
		debug << "add (" << arr(a, i) << ") * (" << name(2 * i - (n - 1ll)) << ")" << endl;
	}
	FORD(i, n - 1, 0) {
		cou[a[i]]++;
		debug << name(cou) << endl;
		sum.PB(-cou[a[i] + 1]);
		sum.PB(cou[a[i] - 1]);
		debug << "+= " << arr(cou, a[i] + 1) << "-= " << arr(cou, a[i] - 1) << endl;
	}
	string pos = parse(sum, 40);
	for (auto & c : sum)
		c *= -1;
	string neg = parse(sum, 40);
	if (pos[0] == '9')
		printf("-%s\n", crop(neg).c_str());
	else
		printf("%s\n", crop(pos).c_str());
}