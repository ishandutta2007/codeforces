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

#define count asntoehu
const int MN = 1e5 + 44;
char a[MN];
int count[128];
int main() {
	scanf("%s", a);
	for (int i = 0; a[i]; ++i)
		count[a[i]]++;
	int res = MN;
	mini(res, count['B']);
	mini(res, count['u'] / 2);
	mini(res, count['l']);
	mini(res, count['b']);
	mini(res, count['a'] / 2);
	
	mini(res, count['s']);
	
	mini(res, count['r']);
	printf("%d\n", res);
}