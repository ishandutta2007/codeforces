#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
 
#define int long long // 
 
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
 
#define MAXN 1000005 //
int n, a[MAXN], k;
char qaq[1000005];
int qwq[1000005];
signed main()
{
	int T = read();
	while(T--) {
		int n = read();
		printf("1");
		int idx = 0;
		while (n) {
			int x = 2;
			for (int i = 2; (i * (i - 1) / 2) <= n; i++) x = i;
			qwq[++idx] = x;
			n -= (x * (x - 1) >> 1);
		}
		sort(qwq +1, qwq+1+idx); 
		For(i, 1, idx) {
			For(j, qwq[i-1]+1, qwq[i]) {
				printf("3");
			}
			printf("7");
		}
		printf("\n");
//		puts(qaq);
	}
	
    return 0;
}