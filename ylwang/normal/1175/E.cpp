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
#define MAXN 500005
int a[MAXN], n, m, Qnum;
int l[MAXN], r[MAXN];
int f[MAXN][25];
signed main()
{
	n = reaD(), m = 0, Qnum = read();
	For(i, 1, n)
		l[i] = read(), r[i] = read();
	For(i, 1, n) 
		a[l[i]] = max(a[l[i]], r[i]), m = max(m, r[i]);
	memset(f, -1, sizeof(f));
	For(i, 1, m) a[i] = max(a[i], a[i-1]);
	For(i, 0, m)
		f[i][0] =  a[i];
	For(j, 1, 20) {
		For(i, 0, m) {
			if(f[i][j-1] != -1) f[i][j] = f[f[i][j-1]][j-1];
		}
	}
	while(Qnum--) {
		int l = read(), r = read(), ans = 0;
		for(int j = 20; j >= 0; j--) {
			if(f[l][j] < r && f[l][j] != -1) {
				ans += (1 << j);
				l = f[l][j];
			}
		}
		if(a[l] >= r) printf("%d\n", ans+1);
		else printf("-1\n");
	} 
    return 0;
}