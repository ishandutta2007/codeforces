#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
 
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 2002 //
int n, m;
int dis[MAXN][MAXN];
int mp[MAXN][MAXN], a[MAXN*MAXN];
signed main()
{
	n = read();
	For(i, 1, n) {
		For(j, 1, n){
			scanf("%1d", &mp[i][j]);
			if(!mp[i][j])
				mp[i][j] = (1ll << 29);
			dis[i][j] = mp[i][j];
		}
		dis[i][i] = 0;
	}
	For(k, 1, n) 
		For(i, 1, n) 
			For(j, 1, n)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	m = read();
	For(i, 1, m) a[i] = read();
	vector < int > ans;
	ans.push_back(a[1]);
	for(int i = 1; i < m; ) {
		for(int j = min(m, i+n+1); j > i; j--) {
			if(dis[a[i]][a[j]] == j - i) {
				ans.push_back(a[j]);
				i = j;
				break;
			}
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    return 0;
}