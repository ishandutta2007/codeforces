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
const int MK = 10;
struct group {
	int low[MK], high[MK];
	int size;
	int nr;
};
bool operator< (group a, group b) {
	return MP(a.low[0], a.nr) < MP(b.low[0], b.nr);
}
group operator+ (group a, group b) {
	group ret;
	REP(i, MK) {
		ret.low[i] = min(a.low[i], b.low[i]);
		ret.high[i] = max(a.high[i], b.high[i]);
	}
	ret.size = a.size + b.size;
	ret.nr = a.nr;
	return ret;
}
ostream & operator<< (ostream & os, group a) {
	os << "{";
	REP(i, MK)
		os << MP(a.low[i], a.high[i]) << ' ';
	os << "}_" << a.size;
	return os;
}
bool disjoint(group a, group b) {
	debug << "disjoint " << name(a) << name(b) << endl;
	REP(i, MK)
		if (a.high[i] > b.low[i]) {
			debug << "no " << arr(a.high, i) << arr(b.low, i) << endl;
			return false;
		}
	debug << "yes" << endl;
	return true;
}
set <group> groups;
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	REP(i, n) {
		group curr;
		REP(j, k) {
			scanf("%d", &curr.low[j]);
			curr.high[j] = curr.low[j];
		}
		curr.nr = i;
		FOR(j, k, MK)
			curr.low[j] = curr.high[j] = curr.low[0];
		debug << name(curr) << endl;
		curr.size = 1;
		auto it = groups.insert(curr).f;
		while (it != groups.begin()) {
			debug << name(groups) << endl;
			auto it2 = it--;
			debug << "test " << name(*it) << name(*it2) << endl;
			if (disjoint(*it, *it2)) {
				it++;
				break;
			}
			auto next = *it + *it2;
			groups.erase(it);
			groups.erase(it2);
			it = groups.insert(next).f;
		}
		while (true) {
			debug << name(groups) << endl;
			auto it2 = it++;
			debug << "test " << name(*it2) << name(*it) << endl;
			if (it == groups.end() || disjoint(*it2, *it))
				break;
			group next = *it + *it2;
			groups.erase(it);
			groups.erase(it2);
			it = groups.insert(next).f;
		}
		printf("%d\n", (--groups.end())-> size);
		debug << "at end " << groups << endl;
	}
}