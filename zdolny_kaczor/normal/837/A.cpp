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
int main() {
	int n;
	scanf("%d", &n);
	int c;
	while ((c=getchar() != '\n')) ;
		
	int ans = 0, curr = 0;
	while ((c = getchar()) != '\n') {
		debug("read %c\n", c);
		if (c == ' ')
			curr = 0;
		else if (c >= 'A' && c <= 'Z') {
			curr++;
			maxi(ans, curr);
		}
	}
	printf("%d\n", ans);
}