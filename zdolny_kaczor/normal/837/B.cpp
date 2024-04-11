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
char in[MN][MN];
int n, m;
bool checkv(char ord[3]) {
	debug("checkv %s\n", ord);
	if (n % 3)
		return false;
	int w = n / 3;
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			if (in[i][k] != ord[i / w]) {
				debug("fail in %d %d\n", i, k);
				return false;
			}
	return true;
}
bool checkh(char ord[3]) {
	debug("checkh %s\n", ord);
	if (m % 3)
		return false;
	int w = m / 3;
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			if (in[i][k] != ord[k / w]) {
				debug("fail in %d %d\n", i, k);
				return false;
			}
	return true;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", in[i]);
	char ord[] = "BGR";
	do {
		if (checkv(ord) || checkh(ord)) {
			printf("YES\n");
			return 0;
		}
	}
	while (next_permutation(ord, ord + 3));
	printf("NO\n");
}