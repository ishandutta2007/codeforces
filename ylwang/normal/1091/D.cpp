#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 1000005
#define MOD 998244353
int f[MAXN];
int fra[MAXN] = {1};
signed main()
{
	int n = read();
	For(i, 1, n) fra[i] = (i * fra[i-1])% MOD;
	f[0] = 1;
	For(i, 1, n) f[i] = (f[i-1] + fra[i-1] - 1) * i % MOD;
	cout << f[n] << endl;
    return 0;
}
/*

*/