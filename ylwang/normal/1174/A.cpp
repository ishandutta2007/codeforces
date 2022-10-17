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
#define MAXN 200005
int n, a[MAXN];
signed main()
{
	srand(time(0));
	n = read();
	For(i, 1, 2 * n)
		scanf("%d", &a[i]);
	For(i, 1, 10000) {
		random_shuffle(a + 1, a + 1 + 2 * n);
		int sum1 = 0;
		For(i, 1, n) sum1 += a[i];
		For(i, n+1, 2*n) sum1 -= a[i];
		if(sum1 != 0) {
			For(i, 1, 2 * n) cout << a[i] << ' ';
			return 0;
		}
	}
	cout << -1 << endl;
    return 0;
}