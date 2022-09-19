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
const int MN = 500;
short dp[MN][MN][MN];
enum {
	TAKE, U1, U2
};
map <int, int> rnr;
int a[MN], b[MN];
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		rnr[a[i]];
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		rnr[b[i]];
		scanf("%d", b + i);
	}
	int cou = 0;
	for (auto & x : rnr)
		x.second = cou++;
	for (int i = n - 1; i >= 0; --i)
		for (int k = m - 1; k >= 0; --k)
			for (int dep = 0; dep < cou; ++dep) {
				if (a[i] == b[k] && rnr[a[i]] >= dep)
					dp[i][k][dep] = dp[i + 1][k + 1][rnr[a[i]] + 1] + 1;
				if (dp[i + 1][k][dep] > dp[i][k][dep])
					dp[i][k][dep] = dp[i + 1][k][dep];
				if (dp[i][k + 1][dep] > dp[i][k][dep])
					dp[i][k][dep] = dp[i][k + 1][dep];
			}
	printf("%d\n", dp[0][0][0]);
	int x = 0, y = 0, dep = 0;
	while (x < n && y < m && dep < cou) {
		if (dp[x + 1][y][dep] == dp[x][y][dep])
			x++;
		else if (dp[x][y + 1][dep] == dp[x][y][dep])
			y++;
		else {
			printf("%d ", a[x]);
			dep = rnr[a[x]] + 1;
			x++;
			y++;
		}
	}
	printf("\n");
}