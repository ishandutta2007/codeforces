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
int n, m, k, a[MAXN];
signed main() 
{
	int T = read();
	while(T--) {
		n = read(), m = read(), k = read();
		For(i, 1, n) a[i] = read();
		For(i, 1, n-1) {
			int now = a[i] + k;
			if(now <= a[i+1]) {
				m -= a[i+1]-now;
				if(m < 0) {
					printf("NO\n");
					goto end;
				}
			}
			else m += min(a[i], now - a[i+1]);
		}
		printf("YES\n");
		end:;
	}
    return 0;
}