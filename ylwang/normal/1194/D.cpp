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
#define MAXN 100005
int a[MAXN];
signed main()
{
	int T = read();
	while(T--) {
		int n = read(), k = read();
		if(k % 3) {
			n % 3 ? printf("Alice\n") : printf("Bob\n");
		} else {
			int qwq = n % (k + 1);
			if(qwq == 0 || (!(qwq % 3) && qwq != k)) {
				printf("Bob\n");
			} else {
				printf("Alice\n");
			}
		}
	}
    return 0;
}