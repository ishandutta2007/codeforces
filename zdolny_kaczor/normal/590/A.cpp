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
const int MN = 5e5 + 44;
int a[MN];
int main() {
	int n;
	scanf("%d", &n);
	int res = 0;
	FOR(i, 1, n)
		scanf("%d", a + i);
	a[0] = a[1];
	a[n + 1] = a[n];
	VPII stable;
	FOR(i, 0, n)
		if (a[i] == a[i + 1])
			stable.PB(MP(i, a[i]));
	FOR(i, 0, siz(stable) - 2) {
		auto first = stable[i], second = stable[i + 1];
		maxi(res, (second.f - first.f - 1) / 2);
		for (int k = first.f + 2, l = second.f - 1; k <= l; k++, l--) {
			a[k] = first.s;
			a[l] = second.s;
		}
	}
	printf("%d\n", res);
	FOR(i, 1, n)
		printf("%d ", a[i]);
}