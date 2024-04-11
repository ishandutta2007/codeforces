#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int MOD = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= MOD ? t - MOD : t); }
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 200005;
int n, k;
bool check1(int mid) {
	int res = 0, cnt = 2;
	while(mid <= n) {
		res += min(cnt, n - mid + 1);
		cnt <<= 1;
		mid <<= 1;
	}
	return res >= k;
}
bool check2(int mid) {
	int res = 0, cnt = 1;
	while(mid <= n) {
		res += min(cnt, n - mid + 1);
		cnt <<= 1;
		mid <<= 1;
	}
	
	return res >= k;
}
signed main()
{
	cin >> n >> k;
	int l = 1, r = n/2, ans = 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check1(mid*2)) {
			l = mid + 1;
			ans = mid*2;
		} else {
			r = mid - 1;
		}
	}
	l = 1, r = n/2;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check2(mid*2+1)) {
			l = mid + 1;
			ckmax(ans, mid*2+1);
		} else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
    return 0;
}