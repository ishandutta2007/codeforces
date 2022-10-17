#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define int long long
int n, k, a[1000005];
#define MAXN 100005
signed main()
{
	cin >> n >> k;
	For(i, 1, n) a[i] = read();
	sort(a + 1, a + 1 + n);
	int l=1,r=n;
	while(a[l] == a[l+1])	l++;
	while(a[r] == a[r-1])	r--;
	while(l < r) {
		if(l >= n - r + 1) {
			int t = (n - r + 1) * (a[r] - a[r-1]);
			if(k < t) {
				cout << a[r] - k / (n-r+1) - a[l];
				return 0;
			}
			k -= t;
			r--;
			while(a[r] == a[r-1])	r--;
		} else {
			int t = - (l) * (a[l] - a[l+1]);
			if(k < t) {
				cout << a[r] - k / l - a[l];
				return 0;
			}
			k -= t;
			l++;
			while(a[l] == a[l+1])	l++;
		}
	}
	cout << 0 << endl;
    return 0;
}