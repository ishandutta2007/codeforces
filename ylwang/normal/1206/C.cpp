#pragma GCC optimize(3)
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
#define MAXN 200005 
int a[MAXN], n;
signed main()
{
	n = read();
	if(n % 2 == 0) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int mn = 1, mx = n << 1;
	For(i, 1, n) {
		if(i&1) a[i] = mx, a[i+n] = mx-1, mx -= 2;
		else a[i] = mn, a[i+n] = mn+1, mn += 2;
	}
	For(i, 1, 2*n) printf("%d ", a[i]);
    return 0;
}