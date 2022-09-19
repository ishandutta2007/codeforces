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
#endif
bool is[16];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int x = 0;
		for (int j = 0; j < k; ++j) {
			int l;
			scanf("%d", &l);
			x = x * 2 + l;
		}
		is[x] = true;	
	}
	for (int i = 0; i < 16; ++i)
		for (int k = 0; k < 16; ++k)
			if (is[i] && is[k] && (i & k) == 0) {
				printf("YES\n");
				return 0;
			}
	printf("NO\n");
}