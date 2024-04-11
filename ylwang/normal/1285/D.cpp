#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= MOD ? t - MOD : t); }
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 100005;
int a[MAXN], n;
int tr[MAXN*30][2], tot = 0;
void insert(int val) {
	int now = 0;
	for(int i = 30; i >= 0; i--) {
		int op = ((val >> i) & 1); 
		if(!tr[now][op]) 
			tr[now][op] = ++tot;
		now = tr[now][op];
	}
}
int dp[MAXN*30]; 
void dfs(int u, int dep) {
	if(tr[u][0]) dfs(tr[u][0], dep-1);
	if(tr[u][1]) dfs(tr[u][1], dep-1);
	if(!tr[u][0]) dp[u] = dp[tr[u][1]];
	else if(!tr[u][1]) dp[u] = dp[tr[u][0]];
	else {
		dp[u] = min(dp[tr[u][1]], dp[tr[u][0]]) + (1 << dep);
	}
}
signed main()
{
	cin >> n;
	For(i, 1, n) a[i] = read();
	For(i, 1, n)
		insert(a[i]);
	dfs(0, 30);
	cout << dp[0] << endl;
    return 0;
}