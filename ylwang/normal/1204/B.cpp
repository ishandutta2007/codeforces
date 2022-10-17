#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define reaD() read()
using namespace std;
#define int long long //
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 2000005
int n, l, r, a[MAXN];
int mc[MAXN];
signed main() 
{
	n = read(), l = read(), r = read();
	mc[0]= 1;
	For(i, 1, r) mc[i] = mc[i-1] * 2;
	int mn = n-l+1, mx = 0;
	For(i, 1, n-(n-l+1)) {
		mn += mc[i];
	}
	cout << mn << ' ';
	For(i, 0, r-2) {
		mx += mc[i];
	}
	cout << mx + (n-r+1) * mc[r-1] <<endl;
    return 0;
}