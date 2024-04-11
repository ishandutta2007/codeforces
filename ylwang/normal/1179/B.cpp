#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
signed main()
{
	int n = read(), m = read();
	For(i, 1, n/2) {
		For(j, 1, m) {
			printf("%d %d\n", i, j);
			printf("%d %d\n", n-i+1, m-j+1);
		}
	}
	if(n % 2 == 1) {
		For(j, 1, m/2) {
			printf("%d %d\n", n/2+1, j);
			printf("%d %d\n", n/2+1, m-j+1);
		}
		if(m % 2 == 1) printf("%d %d\n", n/2+1, m/2+1);
	}
    return 0;
}