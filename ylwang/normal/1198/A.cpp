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
 
int n, a[MAXN], b[MAXN], m, cnt, c[MAXN], qwq[MAXN];
int sum[MAXN];
signed main()
{
	n = read(), m = read();
	For(i, 1, n)
		a[i] = b[i] = read();
	sort(b + 1, b + n + 1);
	cnt = unique(b + 1, b + n + 1) - b - 1;
	For(i, 1, n) {
		a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
		c[a[i]]++;
	}
	qwq[0] = 1;
	for (int i = 1; i <= 30; i++) {
		qwq[i] = qwq[i - 1] << 1;
		if (qwq[i] >= cnt && i <= 8 * m / n) {
			cout << 0;
			return 0;
		}
	}
	int tot = qwq[8*m/n];
	For(i, 1, cnt) sum[i] = sum[i-1]+c[i];
	int ans = (1ll << 31) - 1;
	For(i, tot, cnt)
		ans = min(ans, sum[cnt] - sum[i] + sum[i - tot]);
	cout << ans << endl;
    return 0;
}