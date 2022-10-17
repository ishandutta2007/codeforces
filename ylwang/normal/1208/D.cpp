#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
 
 
using namespace std;
#define int long long
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
 
 
#define MAXN 500005 //
int n, a[MAXN], s[MAXN], tar[MAXN], d[MAXN], c[MAXN];
int ans[MAXN];
#define lowbit(x) (x&(-x))
inline int query(int x) {
	int ans = 0;
	for(; x; x -= lowbit(x)) ans += c[x];
	return ans;
}
inline void tardate(int x, int val) {
	for(; x <= n; x += lowbit(x)) c[x] += val;
}
inline int qaq(int x) {
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(query(mid) <= x) l = mid;
		else r = mid-1; 
	}
	return l;
}
signed main()
{
	n = read();
	For(i, 1, n) a[i] = read();
	For(i, 1, n) tar[i] = tar[i-1] + i - 1;
	For(i, 1, n) c[i] = tar[i] - tar[i-lowbit(i)];
	for(int i = n; i >= 1; i--) {
		int qwq = qaq(a[i]);
		ans[i] = qwq;
		tardate(qwq+1, -qwq);
	}
	For(i, 1, n) {
		printf("%I64d ", ans[i]);
	}
    return 0;
}