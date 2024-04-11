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
#define Foe(i, u) for(register int i = lst[u]; i; i = e[i].nxt)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin);freopen(s".out", "w", stdout)
#define INF ((1 << 30) - 1)
#define dprintf(x) fprintf(stderr, "%d ", x)
#define dprintfln(x) fprintf(stderr, "%d\n", x)
#define dln fprintf(stderr, "\n")

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
const int MAXN = 1e6 + 5;
int a[MAXN], b[MAXN], n, q;
int t[MAXN];
	int c[MAXN];
	void update(int x, int v) {
//		cout << x << endl;
		for(; x <= n; x += (x&-x)) c[x] += v;
	}
	int query(int x) {
		int res = 0;
		for(; x > 0; x -= (x&-x)) res += c[x];
		return res;
	}
signed main()
{
	n = read(), q =read();
	For(i, 1, n) {
		int x = read(); 
		update(x, 1);
	}
	For(i, 1, q) b[i] = read();
	For(i, 1, q) {
		if(b[i] > 0) {
//			cout << "*";
			update(b[i], 1);
		} else {
			int l = 1, r = n, oo = 0;
			while(l <= r) {
				int mid = (l + r) >> 1;
//				cout << mid << ' ' << query(mid) << endl;
				if(query(mid) < -b[i]) {
					 l = mid + 1;
//					cout << mid << endl;
				} else {
					r = mid - 1;oo = mid;
				}
			}
			update(oo, -1);
//			cout<< oo << endl;
		}
	}
	For(i, 1, n) {
		int t = query(i) - query(i - 1);
		if(t) {
			printf("%d\n", i);
			return 0;
		}
	}
		cout << 0 << endl;
    return 0;
}