#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647/3
#define ll long long
#define int long long 
using namespace std;
inline int read()
{
    int num=0;char c=' ';
    for(;c>'9'||c<'0';c=getchar());
    for(;c>='0'&&c<='9';num=(num*10+c-48),c=getchar());
    return num;
}
#define MAXN 300005
int n, k, MOD, a[MAXN], fac[MAXN];
map < int, int > num;

signed main()
{
	n = read(), MOD = read(), k = read();
	k = k % MOD;
	for(int i = 1; i <= n; i++) {
		int A = read();
		int tmp = (A * A) % MOD;
		tmp = (tmp * tmp) % MOD;
		a[i] = ((tmp - k * A) % MOD + MOD) % MOD;
	}
	
	for(int i = 1; i <= n; i++)
		num[a[i]]++;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int qwq = num[a[i]];
		ans += qwq * (qwq - 1);
		num[a[i]] = 0;
	}
	cout << ans / 2<< endl;
	return 0;
}