#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
 
#define int long long//
 
#define reaD() read()
 
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005 //
#define MOD 998244353
int n, m; 
inline int ksm(int a, int b) {
	int ans = 1;
	while(b) {
		if(b & 1) 
			ans = (ans * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return ans;
}
signed main()
{
	n = read(), m = read();
	cout << ksm(2, n+m) << endl;
    return 0;
}