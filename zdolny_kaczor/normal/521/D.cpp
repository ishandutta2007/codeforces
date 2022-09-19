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
const int MN = 1e5 + 44;
VPII mul;
LL val[MN];
PII opt_set[MN];
VPII add[MN];
bool type1[MN];
struct adder {
	PLL factor;
	int nr;
	int pos;
	int val;
	adder(PLL f, int n, int p, int v) : factor(f), nr(n), pos(p), val(v) {}
};
ostream & operator << (ostream & os, adder x) {
	return os << "[" << x.factor.f << "/" << x.factor.s << " +=" << x.val << " at " << x.pos << "]_" << x.nr;
}
bool operator< (adder a1, adder a2) {
	return MP(a1.factor.f * 1ll * a2.factor.s, a1.nr) > MP(a2.factor.f * 1ll * a1.factor.s, a2.nr);
}
adder top_from(int i) {
	while (add[i].empty())
		;
	assert(!add[i].empty());
	return adder(MP(val[i] + add[i].back().f, val[i]), add[i].back().s, i, add[i].back().f);
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &k, &n, &m);
	FOR(i, 1, k) {
		scanf("%lld", val + i);
		opt_set[i] = MP((int)val[i], INT_MAX);
	}
	FOR(i, 1, n) {
		int t, nr, val;
		scanf("%d%d%d", &t, &nr, &val);
		if (t == 3)
			mul.PB(MP(val, i));
		else if (t == 2) {
			add[nr].PB(MP(val, i));
		}
		else {
			type1[i] = true;
			maxi(opt_set[nr], MP(val, i));
		}
	}
	set <adder> adds;
	FOR(i, 1, k) {
		if (opt_set[i].s != INT_MAX)
			add[i].PB(MP(opt_set[i].f - val[i], opt_set[i].s));
		sort(ALL(add[i]));
		if (!add[i].empty())
			adds.insert(top_from(i));
		debug << arr(add, i) << endl;
	}
	sort(ALL(mul));
	VI ans1, ans2, ans3;
	int res = 0;
	while (siz(ans1) + siz(ans2) + siz(ans3) < m && (!adds.empty() || !mul.empty())) {
		debug << name(adds) << name(mul) << endl;
		debug << name(ans1) << name(ans2) << name(ans3) << endl;
		PII mcand = mul.empty() ? MP(0, 0) : mul.back();
		adder acand = adds.empty() ? adder(MP(0, 1), 0, 0, 0) : *adds.begin();
		debug << name(mcand) << name(acand) << endl;
		
		if (mcand.f * 1ll * acand.factor.s > acand.factor.f) { //add mcand
			debug << "take mul" << endl;
			ans3.PB(mcand.s);
			mul.pop_back();
		}
		else { //add acand
			debug << "take add" << endl;
			if (type1[acand.nr])
				ans1.PB(acand.nr);
			else
				ans2.PB(acand.nr);
			val[acand.pos] += acand.val;
			add[acand.pos].pop_back();
			adds.erase(adds.begin());
			if (!add[acand.pos].empty())
				adds.insert(top_from(acand.pos));
		}
	}
	printf("%d\n", siz(ans1) + siz(ans2) + siz(ans3));
	for (int x : ans1)
		printf("%d ", x);
	for (int x : ans2)
		printf("%d ", x);
	for (int x : ans3)
		printf("%d ", x);
	printf("\n");
}