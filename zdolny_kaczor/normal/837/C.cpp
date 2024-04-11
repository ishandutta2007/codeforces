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
const int MN = 101;
PII in[MN];
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &in[i].f, &in[i].s);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int k = i + 1; k < n; ++k) {
			for (int x = 0; x < 8; ++x) {
				if (x & 1)
					swap(in[i].f, in[i].s);
				if (x & 2)
					swap(in[k].f, in[k].s);
				if (x & 4)
					swap(a, b);
				if (max(in[i].f, in[k].f) <= a && in[i].s + in[k].s <= b)
					maxi(ans, in[i].f * in[i].s + in[k].f * in[k].s);
				if (x & 1)
					swap(in[i].f, in[i].s);
				if (x & 2)
					swap(in[k].f, in[k].s);
				if (x & 4)
					swap(a, b);
			}
		}
	printf("%d\n", ans);
}