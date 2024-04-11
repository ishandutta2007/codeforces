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
bool is_prime(int p) {
	for (int i = 2; i * i <= p; ++i)
		if (p % i == 0)
			return false;
	return true;
}
const LL BOUND = deb ? 1000 : (LL)1e18 + 5;
vector <LL> generate(vector <int> primes) {
	if (primes.size() == 0) {
		return {1LL};
	}
	int p = primes.back();
	primes.pop_back();
	vector <LL> ans;
	for (LL x : generate(primes)) {
		ans.PB(x);
		while (x * (LD)p < BOUND) {
			x *= p;
			ans.PB(x);
		}
	}
	return ans;
}
LL under(vector <LL> &n1, vector <LL> &n2, LL bound) {
	int less = siz(n1);
	LL ans = 0;
	for (LL x : n2) {
		debug << arr(n1, less - 1) << endl << name(x) << name(bound);
		while (less > 0 && bound / n1[less - 1] < x)
			less--;
		debug << "add " << name(less) << arr(n1, less) << "at " << name(x) << endl;
		ans += less;
	}
	debug << name(ans) << endl;
	return ans;
}
int main() {
	VI primes[2];
	int n;
	LL k;
	scanf("%d", &n);
	int cou = 0;
	while (cou < n) {
		int p;
		scanf("%d", &p);
		primes[!!(++cou&2)].push_back(p);
	}
	scanf("%lld", &k);
	debug << name(primes[0]) << name(primes[1]) << endl;
	LL pro[2] = {1, 1};
	REP(i, 2)
		for (int p : primes[i]) {
			pro[i] *= (int) (log(1e18) / log(p));
		}
	debug << range(pro, 0, 1) << endl;
	auto n1 = generate(primes[0]), n2 = generate(primes[1]);
	sort(ALL(n1));
	sort(ALL(n2));
	debug << name(siz(n1)) << name(siz(n2)) << name(siz(n1) + siz(n2)) << endl;
	debug << name(n1) << name(n2) << endl;
	LL low = 0, high = BOUND, ans = -1410;
	while (low <= high) {
		LL med = (low + high) / 2;
		debug << name(low) << name(med) << name(high) << endl;
		if (under(n1, n2, med) >= k) {
			ans = med;
			high = med - 1;
		}
		else {
			low = med + 1;
		}
	}
	printf("%lld\n", ans);
}