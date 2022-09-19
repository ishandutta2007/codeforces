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
const int MN = 1e5 + 44;
int a[MN];
stack <int> last;
VPII ans;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i <= n + 1; ++i) {
		for (int k = 0; k < a[i] - a[i - 1]; ++k)
			last.push(i);
		for (int k = 0; k < a[i - 1] - a[i]; ++k) {
			ans.PB(MP(last.top(), i - 1));
			last.pop();
		}
	}
	printf("%d\n", siz(ans));
	for (auto x : ans)
		printf("%d %d\n", x.f, x.s);
	
}