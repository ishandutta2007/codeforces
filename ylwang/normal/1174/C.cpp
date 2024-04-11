#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 200005
int n, ans[MAXN];
int prime[MAXN], v[MAXN], tot = 0, m;
inline int get_p(int n) {
	memset(v, 0, sizeof(v));
	v[1] = 1;
	For(i, 2, n) {
		if(!v[i])
			v[i] = i, prime[++tot] = i;
		for(int j = 1; j <= tot; j++) {
			if(v[i] < prime[j] || i * prime[j] > n) break;
			v[i * prime[j]] = prime[j];
		}
	}
}
 
signed main()
{
	srand(time(0));
	n = read(); get_p(n + 5);
	int cnt = 0;
	For(i, 2, n) {
		if(v[i] == i) {
			cnt++;
			for(int j = i; j <= n; j += i) {
				ans[j] = cnt;
			}
		}
	}
	For(i, 2, n) printf("%d ", ans[i]);
    return 0;
}