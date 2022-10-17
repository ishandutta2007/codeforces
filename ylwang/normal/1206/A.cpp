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
#define MAXN 105 
int a[MAXN], b[MAXN];
signed main()
{
	int n, m;
	n = read();
	For(i, 1, n) a[i] = read();
	m = read();
	For(i, 1, m) b[i] = read();
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	cout<<a[n] << ' ' << b[m] << endl;
    return 0;
}