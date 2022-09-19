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
const int MN = 1e5 + 44;
int a[MN];
void err() {
	printf("NO\n");
	exit(0);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	if (n == 1) {
		if (a[0])
			printf("NO\n");
		else
			printf("YES\n0\n");
		return 0;
	}
	if (a[n - 1] == 1)
		err();
	int f = -1;
	for (int i = 0; i < n - 1; ++i)
		if (a[i] == 0) {
			f = i;
			break;
		}
	if (f == n - 2)
		err();
	else if (f == -1) {
		printf("YES\n");
		for (int i = 0; i < n; ++i) {
			if (i)
				printf("->");
			printf("%d", a[i]);
		}
		return 0;
	}
	printf("YES\n");
	printf("(");
	for (int i = 0; i <= f; ++i) {
		if (i)
			printf("->");
		printf("%d", a[i]);
	}
	printf(")->(");
	for (int i = f + 1; i < n - 1; ++i) {
		if (i != f + 1)
			printf("->");
		printf("%d", a[i]);
	}
	printf(")->(0)");
}