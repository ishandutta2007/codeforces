#include <bits/stdc++.h>
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
const int MN = 2e6 + 44;
int u[MN];
void rem(int x) {
	if (u[x] == x)
		u[x] = x + 1;
}
int find(int x) {
	if (u[x] == x)
		return x;
	else
		return u[x] = find(u[x]);
}
char ans[MN];
char in[MN];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < MN; ++i)
		u[i] = i;
	for (int i = 0; i < n; ++i) {
		scanf("%s", in);
		int c;
		scanf("%d", &c);
		int len = strlen(in);
		for (int i = 0; i < c; ++i) {
			int x;
			scanf("%d", &x);
			int pos = find(x);
			while (pos < x + len) {
				ans[pos] = in[pos - x];
				rem(pos);
				pos = find(pos);
			}
		}
	}
	bool seen = false;
	for (int i = MN - 1; i >= 0; --i) {
		if (ans[i])
			seen = true;
		if (ans[i] == 0 && seen)
			ans[i] = 'a';
	}
	printf("%s\n", ans + 1);
}