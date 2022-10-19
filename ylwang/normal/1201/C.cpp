#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define int long long
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005
int n, k, a[MAXN];
inline bool check(int val) {
//	cout << val << endl;
	int cnt = 0;
	For(i, 1, n)
		if(a[i] <= val)
			cnt += (val - a[i]);
	return cnt <= k;
}
signed main()
{
	n = read(), k = read();
	For(i, 1, n) a[i] = read();
	sort(a + 1, a + 1 + n);
	int pos = n / 2 + 1;
	n = pos;
	For(i, 1, n) a[i] = a[i+n-1];
	int l = 1, r = (1ll << 31)-1, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			l = mid+1, ans = mid;
		} else r = mid-1;
	}
	cout << ans << endl;
    return 0;
}