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
#define MAXN 2005
int a[MAXN][MAXN], n;
int ans[MAXN][MAXN];
signed main()
{
	n = read();
	For(i, 1, 4) {
		For(j, 1, 4) {
			a[i][j] = (i-1)*4+(j-1);
		}
	}
	int m = n / 4;
	int cnt = 0;
	For(i, 1, m) {
		For(j, 1, m) {
			For(r, 1, 4) {
				For(k, 1, 4) {
					ans[(i-1)*4+r][(j-1)*4+k] = a[r][k] + 16 * cnt;
					
				}
			}cnt++;
		} 
	}
	For(i, 1, n) {
		For(j, 1, n) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
    return 0;
}