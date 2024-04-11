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
int n, a[MAXN], m, k;
int diver[15], ans = 0;
inline void solve(int l, int r) {
	if(l == r) {
		ans = max(ans, a[l] - k);
		return;
	}
	memset(diver, 0, sizeof(diver));
	int sum = 0, len = 0, sta = 0, mid = (l + r) >> 1;
	for(int i = mid; i >= l; i--) {
		sum += a[i], len++, sta++;
		if(sta == m) sta = 0;
		diver[sta] = max(diver[sta], sum - k * (len / m));
	}
	sum = 0, len = 0, sta = 0;
	For(i, mid+1, r) {
		sum += a[i], len++, sta++;
		if(sta == m) sta = 0;
		For(j, 0, m) {
			int nowans = sum - k * (len / m) + diver[j];
			ans = max(ans, nowans - k * ((j + sta) / m + !!((j + sta) % m)));
		}
	}
	solve(l, mid);
	solve(mid+1, r);
}
signed main()
{
	n = read(), m = read(), k = read();
	For(i, 1, n) a[i] = read();
	solve(1, n);
	cout << ans << endl;
    return 0;
}