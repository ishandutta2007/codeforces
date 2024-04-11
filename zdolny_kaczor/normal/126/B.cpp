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
#define pow rcshnt
const int MN = 1e6 + 44;
const int mod = 1e9 + 9, b = 888883;
LL pow[MN];
int n;
char a[MN];
bool check(int len) {
	debug("check %d\n", len);
	LL curr = 0;
	for (int i = 0; i < len; ++i)
		curr = (curr * b + a[i]) % mod;
	LL pre = curr;
	debug("pre = %lld\n", pre);
	for (int i = len; i < n - 1; ++i) {
		debug("start with %lld\n", curr);
		debug("temp = %lld\n", curr - a[i - len] * pow[len - 1]);
		curr = ((curr - a[i - len] * pow[len - 1]) % mod * b + a[i]) % mod;
		debug("curr = %lld\n", curr);
		if ((pre - curr) % mod == 0) {
			debug("found in %d\n", i);
			return true;
		}
	}
	debug("not found\n");
	return false;
}
int main() {
	scanf("%s", a);
	n = strlen(a);
	
	pow[0] = 1;
	for (int i = 1; i < MN; ++i) {
		pow[i] = pow[i - 1] * b % mod;
	}
	for (int i = 0; i < 10; ++i)
		debug("%d ^ %d === %d\n", b, i, pow[i]);
	vector <int> pre;
	LL ph = 0, sh = 0;
	for (int i = 0; i < n - 1; ++i) {
		ph = (ph * b + a[i]) % mod;
		sh = (sh + a[n - i - 1] * pow[i]) % mod;
		if (ph == sh) {
			pre.PB(i + 1);
			debug("pre %d\n", i + 1);
		}
	}
	int low = 1, high = n - 1, ans = 0;
	while (low <= high) {
		int med = (low + high) / 2;
		if (check(med)) {
			ans = med;
			low = med + 1;
		}
		else
			high = med - 1;
	}
	int res = -1;
	for (auto c : pre) {
		if (c <= ans)
			maxi(res, c);
	}
	if (res <= 0) {
		printf("Just a legend\n");
	}
	else {
		a[res] = 0;
		printf("%s\n", a);
	}
}