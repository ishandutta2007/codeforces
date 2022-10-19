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
const int MAXN = 600005;
int n, m, mini[MAXN], maxi[MAXN];
int c[MAXN], pos[MAXN];
void update(int x, int v) {
	for(; x <= n+m; x += (x&-x)) c[x] += v;
}
int query(int x) {
	int ans = 0;
	for(; x; x -= (x&-x)) ans += c[x];
	return ans;
}
signed main()
{
	cin >> n >> m;
	For(i, 1, n) mini[i] = maxi[i] = i;
	For(i, 1, n) pos[i] = m+i, update(pos[i], 1);
	int now = m;
	For(k, 1, m) {
		int i = read(); mini[i] = 1;
		ckmax(maxi[i], query(pos[i]));
		update(pos[i], -1); 
		pos[i] = now; now--;
		update(pos[i], 1);
	}
	For(i, 1, n)
		ckmax(maxi[i], query(pos[i]));
	For(i, 1, n) {
		printf("%d %d\n", mini[i], maxi[i]);
	}
    return 0;
}