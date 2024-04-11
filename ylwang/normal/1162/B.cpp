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
int n, m;
int a[55][55], b[55][55];
signed main()
{
	n = read(), m = read();
	memset(a, 127, sizeof(a));
	memset(b, 127, sizeof(b));
	For(i, 1, n) For(j, 1, m)
		a[i][j] = read();
	For(i, 1, n) For(j, 1, m) 
		b[i][j] = read();
	For(i, 1, n) For(j, 1, m)
		if(a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
	For(i, 1, n) {
		For(j, 1, m) {
			if(a[i][j] >= a[i+1][j] || a[i][j] >= a[i][j+1]) {
				printf("Impossible\n");
				return 0;
			} 
		} 
	}
	For(i, 1, n) {
		For(j, 1, m) {
			if(b[i][j] >= b[i+1][j] || b[i][j] >= b[i][j+1]) {
				printf("Impossible\n");
				return 0;
			} 
		} 
	}
	printf("Possible\n");
    return 0;
}