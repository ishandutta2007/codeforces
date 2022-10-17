#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
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
#define MAXN 1000005 //
 
int n, a[MAXN];
 
signed main()
{
	int T = reaD();
	while(T--) {
		n = read();
		For(i, 1, n) 
			a[i] = read();
		sort(a + 1, a + 1 + n);
		if(n == 2) {
			printf("0\n");
			continue;
		}
		if(a[n-1] == 1) {
			printf("0\n");
		} else {
			printf("%I64d\n", min(n-2, a[n-1]-1));
		}
	}
	
		
    return 0;
}