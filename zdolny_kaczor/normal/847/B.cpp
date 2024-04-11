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
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
const int MN = 2e5 + 44;
int a[MN];
VI ans[MN];
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d", a + i);
	ans[0].PB(a[0]);
	int last = 0;
	FOR(i, 1, n - 1) {
		int found = last + 1;
		int l = 0, r = last;
		while (l <= r) {
			int med = (l + r) / 2;
			if (ans[med].back() < a[i]) {
				found = med;
				r = med - 1;
			}
			else
				l = med + 1;
		}
		ans[found].PB(a[i]);
		maxi(last, found);
	}
	FOR (i, 0, last) {
		for (int c : ans[i])
			printf("%d ", c);
		printf("\n");
	}
}