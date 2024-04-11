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
#define EB emplace_back
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
const bool debug = 
#ifdef DEB
true;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
int snt = 5;
void set_bound(int x) {
	snt = x;
}
template <typename T>
auto htr (T in) -> decltype(cout << in, string()) {
	stringstream s;
	s << boolalpha << in;
	return s.str();
}
template <typename T>
auto htr (T in) -> decltype(in.begin(), string());
template <typename T, typename C>
string htr(pair <T, C> x) {
	return "<" + htr(x.f) + ", " + htr(x.s) + ">";
}
template <typename T>
auto htr (T in) -> decltype(in.begin(), string()) {
	string ret = "{";
	int i = 0;
	for (auto c : in) {
		if (i >= snt) {
			ret += "... (" + to_string(siz(in)) + " elements)";
			break;
		}
		ret += (i++?", ":"") + htr(c);
	}
	return ret + "}";
}
#else
false;
#define debug(...)
#define set_bound(x)
#endif
#define cc(x) x.f, x.s
#define here() debug("LINE: %d\n", __LINE__)
#define str(x) htr(x).c_str()
#define name(x) debug("[line:%d] %s = %s\n", __LINE__, #x, str(x));
int main() {
	int n;
	scanf("%d", &n);
	pair <VI, set <pair <bool, char> > > x;
	set_bound(n);
	for (int i = 0; i < 10; ++i) {
		x.f.PB(i + 3);
		if (i & 1)
			x.s.insert(MP(i % 3 == 0, 'a' + i));
	}
	name(x);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (n - i - 1) * (i + 1);
	}
	printf("%d\n", ans + n);
}