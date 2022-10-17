#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647

using namespace std;

inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 505
int a[MAXN][MAXN];
int ans[MAXN];
signed main()
{
	int n = read(), m = read();
	For(i, 1, n)
		For(j, 1, m)
			a[i][j] = read();
	srand(time(0));
	For(ZTYAKIOI, 1, 100000) {
		For(i, 1, n) ans[i] = rand() % m + 1;
		int xsum = 0;
		For(i, 1, n) {
			xsum ^= a[i][ans[i]];
		}
		if(xsum > 0) {
			printf("TAK\n");
			For(i, 1, n)
				printf("%d ", ans[i]);
			return 0;
		}
	}
	printf("NIE\n");
    return 0;
}
/*

*/