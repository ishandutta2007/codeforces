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
int a[500];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; ++i)
		scanf("%d", a + i);
	sort(a, a + n * 2);
	int ans = 1e9;
	for (int i = 0; i < 2 * n; ++i)
		for (int k = i + 1; k < 2 * n; ++k) {
			int curr = 0, last = -1;
			for (int l = 0; l < 2 * n; ++l)
				if (l != i && l != k) {
					if (last == -1)
						last = a[l];
					else {
						curr += a[l] - last;
						last = -1;
					}
				}
			mini(ans, curr);
		}
	printf("%d\n", ans);
}