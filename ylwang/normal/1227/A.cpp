#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb emplace_back
#define mkp make_pair
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define cp Complex
#define pi acos(-1.0)
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
const int MAXN = 100005;
int n;
struct Line {
	int l, r;
	bool operator < (const Line b) {
		return l < b.l;
	}
}a[MAXN];
signed main()
{
	int T = read();
	while(T--) {
		n = read();
		For(i, 1, n)
			a[i].l = read(), a[i].r = read();
		int al = 0, ar = (1 << 30);
		For(i, 1, n) {
			ckmax(al, a[i].l);
			ckmin(ar, a[i].r);
		}
		cout << max(al - ar, 0) << endl;
	}

    return 0;
}