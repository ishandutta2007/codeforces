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
#else
#define debug(...)
#define cerr if(0) cerr
#endif
#define cc(x) x.f, x.s
#define pow cgrrhtns
LL inv(LL x, LL m) {
	for (int i = 0; ; ++i)
		if (x * i % m == 1)
			return i;
}
const int B = 147, mod = 1e9 + 7, Bin = inv(B, mod);
const int MN = 1e5 + 44;
LL pow[MN];
bool substring(const string & a, const string & b) {
	if (a.size() > b.size())
		return false;
	LL ahash = 0;
	for (auto c : a)
		ahash = (ahash * B + c) % mod;
	LL bhash = 0;
	for (int i = 0; i < siz(a); ++i)
		bhash = (bhash * B + b[i]) % mod;
	if (ahash == bhash)
		return true;
	for (int i = 0; i < siz(b) - siz(a); ++i) {
		bhash = ((bhash - pow[siz(a) - 1] * b[i]) * B + b[i + siz(a)]) % mod;
		if ((ahash - bhash) % mod == 0)
			return true;
	}
	return false;
}
int pref(const string & a, const string & b) {
	int ans = 0;
	LL ahash = 0, bhash = 0;
	REP(i, min(siz(a), siz(b))) {
		ahash = (ahash * B + a[i]) % mod;
		bhash = (bhash + b[siz(b) - i - 1] * pow[i]) % mod;
		if (ahash == bhash)
			ans = i + 1;
	}
	return ans;
}
void sw(string & a, string & b) {
	if (a.size() > b.size())
		swap(a, b);
}
int main() {
	pow[0] = 1;
	FOR(i, 1, MN - 1)
		pow[i] = pow[i - 1] * B % mod;
	string in[3];
	REP(i, 3)
		cin >> in[i];
	vector <string> x;
	sw(in[0], in[1]);
	sw(in[1], in[2]);
	sw(in[0], in[1]);
	REP(i, 3) {
		bool good = true;
		REP(j, 3)
			if (i != j && substring(in[i], in[j]))
				good = false;
		if (good)
			x.PB(in[i]);
	}
	if (x.size() == 0) {
		cout << in[0].size() << endl;
		return 0;
	}
	sort(ALL(x));
	int ans = 1e6;
	do {
		int curr = 0;
		for (auto c : x)
			curr += c.size();
		REP(i, x.size() - 1) {
			curr -= pref(x[i], x[i + 1]);
		}
		mini(ans, curr);
	} while (next_permutation(ALL(x)));
	printf("%d\n", ans);
}