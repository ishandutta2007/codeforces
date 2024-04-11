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
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int MOD = 998244353; //
using namespace std;
#define int long long
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= MOD ? t - MOD : t); }
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=-1;
    for(;c>='0'&&c<='9';num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 100005;
int n, a[MAXN], sum[MAXN];
signed main()
{
	int T = read();
	while(T--) {
		n = read();
		For(i, 1, n) a[i] = read(), sum[i] = sum[i-1] + a[i];
		int msum = 0, maxi = 0;
		For(i, 1, n) {
			if(i != n) ckmax(maxi, sum[i] - msum);
			else For(j, 1, n) ckmax(maxi, sum[i] - sum[j]);
			if(msum > sum[i])
				msum = sum[i];
		}
		if(maxi < sum[n]) puts("YES");
		else puts("NO");
	}
    return 0;
}