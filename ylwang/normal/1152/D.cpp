#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) ;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}
#define MAXN 2005
#define MOD 1000000007
int f[MAXN][MAXN];
bool g[MAXN][MAXN];

signed main()
{
    int n = (read() << 1);
    memset(f, 0, sizeof(f)); memset(g, 0, sizeof(g));
    g[0][0] = 1;
    for(int i = 1; i <= n; i++) {
    	for(int j = 0; j <= i; j++) {
    		int sum = 0;
			bool flag = 0;
    		if(j != 0) sum += f[i-1][j-1], flag |= g[i-1][j-1];
    		if(j + 1 <= i - 1) sum += f[i-1][j+1], flag |= g[i-1][j+1];
    		f[i][j] = (sum + flag) % MOD, g[i][j] = !flag;
		}
	}
	cout << f[n][0] % MOD << endl;
    return 0;
}