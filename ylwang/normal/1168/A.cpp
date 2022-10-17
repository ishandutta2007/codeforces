#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define int long long//
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
//0~n(ai+1)%n
//
#define MAXN 1000005 //
int n, a[MAXN], m;
int tmp[MAXN];
bool check(int mid) {
	For(i, 1, n) a[i] = tmp[i];
	int maxi = 0;
	For(i, 1, n) {
		if(a[i] < maxi) {
			if(a[i] + mid < maxi) return 0;
			else a[i] = maxi;
		} else if(a[i] > maxi) {
			if(a[i] + mid - m >= maxi) continue;
			else maxi = max(maxi, a[i]);
		}
	}
	
	return 1;
}
signed main()
{
	n = read(), m = read();
	For(i, 1, n) tmp[i] = read();
	int l = 0, r = (1ll << 31) - 1, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid-1, ans = mid;
		} else l = mid+1;
	} 
	cout << ans << endl;
    return 0;
}