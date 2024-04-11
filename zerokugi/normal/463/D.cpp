#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,x) for(int i=0;i<(int)(x);i++)

int n, m, x, g[1001][1001], pos[1001][1001];
main(){
	scanf("%d%d", &n, &m);
	REP(i, m)REP(j, n){
		scanf("%d", &x);
		pos[x-1][i] = j;
	}
	REP(i, n)REP(j, n){
		int f = 1;
		REP(k, m) f &= (pos[i][k] < pos[j][k]);
		g[i][j] = f ? 1 : -10000;
	}
	REP(k, n)REP(i, n)REP(j, n)g[i][j] = max(g[i][j], g[i][k] + g[k][j]);
	printf("%d\n", *max_element(&g[0][0], &g[0][0] + 1000*1000) + 1);
	return 0;
}