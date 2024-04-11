#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
int n, h, m;
int a[10005];
signed main()
{
	n = read(), h = read(), m = read();
	For(i, 1, n) a[i] = h;
	For(i, 1, m) {
		int l = read(), r = read(), val = read();
		For(i, l, r) {
			a[i] = min(a[i], val); 
		}
	}
	ll ans = 0;
	For(i, 1, n) {
		ans += a[i] * a[i];
	}
	cout << ans << endl;
    return 0;
}