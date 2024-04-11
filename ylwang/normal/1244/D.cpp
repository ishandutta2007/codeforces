#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
#define int long long
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 500005
int c[4][MAXN], n, deg[MAXN];
vector < int > g[MAXN];
int a[MAXN], m, sum[MAXN];
void dfs(int u, int fa) {
	a[++m] = u;
	for(auto v : g[u]) {
		if(v != fa) {
			dfs(v, u);
		}
	}
}
int tmp[MAXN], num[MAXN];
int get(int x, int y) {
	int ans = 0;
	tmp[1] = x, tmp[2] = y;
	For(i, 3, n) {
		For(j, 1, 3) {
			if(j != tmp[i-1] && j != tmp[i-2]) {
				tmp[i] = j;
			}
		}
	}
	For(i, 1, n) ans += c[tmp[i]][a[i]];
	return ans;
}
signed main()
{
	cin >> n;
	For(i, 1, 3) For(j, 1, n) c[i][j] = read();
	For(i, 1, n-1) {
		int u = read(), v = read();
		g[u].pb(v); g[v].pb(u);
		deg[u]++, deg[v]++;
	}
	For(i, 1, n) {
		if(deg[i] > 2) {
			cout << -1 << endl;
			return 0;
		}
	}
	For(i, 1, n) {
		if(deg[i] == 1) {
			dfs(i, -1);
			break;
		}
	}
	int ans = (1ll << 60);
	For(i, 1, 3) For(j, 1, 3) {
		if(i != j) {
			if(get(i, j) < ans) {
				ans = get(i, j);
				For(i, 1, n) num[a[i]] = tmp[i];
			}
		}
	}
	cout << ans << endl;
	For(i, 1, n) printf("%lld ", num[i]);
    return 0;
}