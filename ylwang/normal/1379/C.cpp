#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define Pair pair < int, int >
#define mkp make_pair
#define rint register int
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define FOr(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin);freopen(s".out", "w", stdout)
#define INF ((1 << 30) - 1)
#define dprintf(x) fprintf(stderr, "%d ", x)
#define dprintfln(x) fprintf(stderr, "%d\n", x)
#define dln fprintf(stderr, "\n")
#define int long long
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;!isdigit(c);c=getchar()) if(c=='-') flag=-1;
    for(;isdigit(c);num=num*10+c-48,c=getchar());
    return num*flag;
}
 
const int MAXN = 2e5 + 5;
int n, m;
struct Node {
	int x, y;
//	bool operator < (Node b) const {return y < b.y;}
}a[MAXN];
bool cmp1(Node a, Node b) {return a.x > b.x;}
//bool cmp2(Node a, Node b) {return a.x + a.y < b.x + b.y; }
int sum[MAXN];
signed main()
{
	int T = read();
	while(T--) {
		n = read(), m = read();
		For(i, 1, m) a[i].x = read(), a[i].y = read();
		sort(a + 1, a + 1 + m, cmp1);
		For(i, 1, m) sum[i] = sum[i-1] + a[i].x;
//		For(i, 1, m) cout << sum[i] << endl;
		int ans = sum[min(n, m)];
//		cout << ans << endl;
			For(i, 1, m) {
				int l = 1, r = m, pos = 0;
				while(l <= r) {
					int mid = (l + r) >> 1;
					if(a[mid].x >= a[i].y) {
						pos = mid, l = mid + 1;
					} else r = mid - 1;
				}
//				cout << i << ' ' << pos << ' ' << ans << endl;
				if(i <= pos && n - pos > 0) ckmax(ans, sum[pos] + (n - pos) * a[i].y);
				else if(i > pos && n - pos - 1 > 0) ckmax(ans, sum[pos] + a[i].x + (n - pos - 1) * a[i].y); 
//				cout << ans << ' ' << sum[pos] << ' ' << a[i].x << ' ' << n - pos - 1 << ' ' << a[i].y << endl;;
//				cout << sum[pos] + a[i].x + (n - pos - 1) * a[i].y << endl;
			}
		cout << ans << endl;
	}
    return 0;
}
/*

*/