#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 8
int n, m, g[10][10];
int p[MAXN], used[MAXN], ans;
int qwq[MAXN][MAXN];
void dfs(int u) {
//	cout << u << endl;
	if(u == n+1) {
		int sum = 0;
		memset(qwq, 0, sizeof(qwq));
		For(i, 1, n) {
			For(j, i+1, n) {
				if(g[i][j] && !qwq[p[i]][p[j]]) {
					qwq[p[i]][p[j]] = qwq[p[j]][p[i]] = 1;
					sum++;
				}
			}
		}
		ans = max(ans, sum);
		return;
	}
	For(i, 1, 6) {
//		if(!used[i]) {
			p[u] = i;
//			used[i] = 1;
			dfs(u+1);
//			used[i] = 0;
//		}
	}
}
signed main()
{
	cin >> n >> m;
	For(i, 1, m) {
		int u = read(), v = read();
		g[u][v] = 1; g[v][u] = 1;
	}
	dfs(1);
	cout << ans << endl;
    return 0;
}