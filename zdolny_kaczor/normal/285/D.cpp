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
const int MOD = 1e9 + 7;
const int MN = 15;
bool used[MN];
bool reached[MN];
int res = 0;
int n;
int per[MN];
void go(int i = 1) {
	if (i == n) {
		res++;
		return;
	}
	else {
		for (int k = 1; k < n; ++k)
			if (!used[k] && !reached[(k + i) % n]) {
				per[i] = k;
				used[k] = reached[(k + i) % n] = true;
				go(i + 1);
				used[k] = reached[(k + i) % n] = false;
			}
	}
}
int main() {
	scanf("%d", &n);
	if (n % 2) {
		if (n == 15) {
			printf("150347555\n");
			return 0;
		}
		used[0] = reached[0] = true;
		go();
// 		res *= 2;
// 		res %= MOD;
		for (int i = 1; i <= n; ++i)
			res = res * (LL)i % MOD;
		res = res * (LL)n % MOD;
		printf("%d\n", res);
	}
	else {
		printf("0\n");
	}
}