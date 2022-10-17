#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long

#define int long long
using namespace std;
inline int read()
{
    int num=0,flag=1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 505
#define mod 1000000007
int a[MAXN][MAXN], d[MAXN][MAXN], f[MAXN][MAXN], n;
inline int m(int x) {
	return x <= n ? x : x % n;
}
signed main()
{
	n = read();
	For(i, 1, n)
		For(j, 1, n) a[i][j] = read();
	For(i, 1, n) d[i][i] = f[i][i] = 1;
	For(len, 2, n) {
		For(i, 1, n) {
			int j = m(i + len - 1);
			for(int k = i; k != j; k = m(k + 1)) {
				if(a[i][j]) d[i][j] = (d[i][j] + f[i][k] * f[m(k+1)][j]) % mod;
				f[i][j] = (f[i][j] + d[i][m(k+1)] * f[m(k+1)][j]) % mod;
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}