#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 105
int n, m, h;
int a[MAXN], b[MAXN], c[MAXN][MAXN], ans[MAXN][MAXN];
signed main()
{
    n = read(), m = read(), h = read();
	For(i, 1, m) cin >> a[i];
    For(i, 1, n) cin >> b[i];
    
    For(i, 1, n) For(j, 1, m) cin >> c[i][j];
//    For(i, 1, n) For(j, 1, m) cout << c[i][j] << ' ';
    For(i, 1, n) {
    	For(j, 1, m) {
    		if(c[i][j] == 1) printf("%d ", min(a[j], b[i]));
    		else printf("%d ", 0);
		}
		printf("\n");
	}
    return 0;
}