#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
#define MAXN 300005
int a[MAXN], n, Qnum;
int dp[MAXN][25];
int w[MAXN];
signed main()
{
	n = read(), Qnum = reaD();
	For(i, 1, n) a[i] = read();
	For(i, 0, n)
		For(j, 0, 21)
			dp[i][j] = n+1, w[j] = -1;
	for(int i = n; i >= 1; i--) {
		For(j, 0, 21) {
			if((a[i] >> j) & 1) {
				For(k, 0, 21)
					if(w[j] != -1) dp[i][k] = min(dp[i][k], dp[w[j]][k]);
				w[j] = i;
				dp[i][j] = min(dp[i][j], i);
			}
			
		}
	}
	while(Qnum--) {
		int x = reaD(), y = reaD();
		For(i, 0, 21) {
			if(((a[y]>>i)&1) && (dp[x][i] <= y)) {
				printf("Shi\n");
				goto end;
			}
		}
		printf("Fou\n");
		end:;
	}
    return 0;
}