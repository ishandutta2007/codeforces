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
#define div d1v
const int MN = 1e5 + 44;
int cou[MN];
int allcou[MN];
int coe[MN];
int div[MN];
const int MOD = 1e9 + 7;
LL p2(int x) {
	if (x == 0)
		return 1;
	else if (x % 2)
		return p2(x - 1) * 2 % MOD;
	else {
		LL h = p2(x / 2);
		return h * h % MOD;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		cou[x]++;
	}
	for (int i = 1; i < MN; ++i)
		for (int k = i; k < MN; k += i)
			allcou[i] += cou[k];
	coe[1] = 1;
	for (int p = 2; p < MN; ++p)
		if (div[p] == 0)
			for (int k = p; k < MN; k += p)
				div[k] = p;
	for (int i = 2; i < MN; ++i)
		if (i / div[i] % div[i] == 0)
			coe[i] = 0;
		else
			coe[i] = -coe[i / div[i]];
	LL res = 0;
	for (int i = 1; i < MN; ++i) {
		res = (res + coe[i] * (p2(allcou[i]) - 1)) % MOD;
	}
	if (res < 0)
		res += MOD;
	printf("%lld\n", res);
}