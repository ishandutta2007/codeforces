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
#define MAXN 3000005
int prime[MAXN], v[MAXN], m = 0;
inline void getp(int n) {
	for(int i = 2; i <= n; i++) {
		if(!v[i]) {
			prime[++m] = i;
			v[i] = i;
		}
		for(int j = 1; j <= m && prime[j] * i <= n; j++) {
			if(v[i] < prime[j]) break;
			v[i * prime[j]] = prime[j];
		}
	}
}
signed main()
{
	int n = read();
	getp(2000000);
	int ans = n;
	for(ans = n; ans <= (n + 1) / 2 * 3; ans++) {
		if(v[ans] == ans) break;
	} 
	cout <<ans << endl;
	For(i, 1, n) {
		printf("%d %d\n", i, i+1 == n+1 ? 1 : i+1);
	}
	int now = 1;
	For(i, n+1, ans) {
		printf("%d %d\n", now, now + n/2);
		now++;
		
	}
    return 0;
}