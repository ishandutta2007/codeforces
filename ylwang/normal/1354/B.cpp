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
#define INF ((1 << 28) - 1)
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
int a[MAXN], n, lst[3][MAXN], nxt[3][MAXN];
signed main()
{
	IOS;
	int T; cin >> T; string s;
	while(T--) {
		cin >> s; n = s.size(); s = ' ' + s;
		int res = n + 1;
		lst[1][0] = -INF, lst[2][0] = -INF;
		nxt[1][n+1] = INF, nxt[2][n+1] = INF;
		For(i, 1, n) {
			lst[1][i] = lst[1][i-1];
			lst[2][i] = lst[2][i-1];
			if(s[i] == '1') {
				lst[1][i] = i;
			} else if(s[i] == '2') {
				lst[2][i] = i;
			}
		}
		foR(i, n, 1) {
			
			nxt[2][i] = nxt[2][i+1];
			nxt[1][i] = nxt[1][i+1];
			if(s[i] == '1') {
				nxt[1][i] = i;
			} else if(s[i] == '2') {
				nxt[2][i] = i;
			}
		} 
		For(i, 1, n) {
			if(s[i] == '3') {
				ckmin(res, i - min(lst[1][i], lst[2][i]) + 1);
				ckmin(res, nxt[1][i] - lst[2][i] + 1);
				ckmin(res, nxt[2][i] - lst[1][i] + 1);
				ckmin(res, max(nxt[1][i], nxt[2][i]) - i + 1);
			}
		}
		if(res != n + 1) cout << res << endl;
		else cout << 0 << endl;
	}
    return 0;
}