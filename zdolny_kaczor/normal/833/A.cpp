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
#define cc(x) x.f, x.s
const int MN = 1e6;
int fac[14];
#define low l
#define high h
bool iscube(LL a) {
	LL l = 0, h = 1e6 + 44;
	while (l <= h) {
		LL med = (l + h) / 2;
		if (med * med * med == a)
			return true;
		else if (med * med * med < a)
			low = med + 1;
		else
			high = med - 1;
	}
	return false;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		LL g = __gcd(a, b);
		if (g * g % a == 0 && g * g % b == 0 && iscube(a * (LL) b))
			printf("Yes\n");
		else
			printf("No\n");
	}
}