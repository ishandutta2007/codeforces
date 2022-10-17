#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long

#define int long long

using namespace std;
inline int read() {
    int num = 0, flag = 1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 1005
int n, m;
int a[MAXN], sum = 0;
inline bool check(int mid) {
	sum = 0;
	For(i, 1, n) {
		if(a[i] >= mid) {
			sum += a[i] - mid;
		} else return 0;
	}
	return sum >= m;
}
signed main()
{
    n = read(), m = read();
    For(i, 1, n)
    	a[i] = read();
    int l = 0, r = 1000000000ll, ans = -1;
    while(l <= r) {
    	int mid = (l + r) >> 1;
    	if(check(mid)) {
    		l = mid+1;
    		ans = mid;
		} else r = mid-1;
	}
	cout << ans << endl;
    return 0;
}