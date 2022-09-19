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
const int MN = 5e3 + 44;
int in[MN];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, n)
		scanf("%d", in + i);
	sort(in, in + n);
	int diff = n / 2;
	int r = 0;
	REP(i, n)
		if (in[i] != in[(i + diff) % n])
			r++;
	printf("%d\n", r);
	REP(i, n)
		printf("%d %d\n", in[i], in[(i + diff) % n]);
}