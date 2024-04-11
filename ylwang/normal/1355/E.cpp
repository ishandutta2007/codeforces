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
#define INF ((1ll << 62) - 1)
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
int n, A, B, C;
const int MAXN = 1e5 + 5;
int a[MAXN], l = INF, r = 0, b[MAXN];
int check(int mid) {
	For(i, 1, n)
		b[i] = a[i] - mid;
	int ans = 0;
	if(C <= A + B) {
		int sum1 = 0, sum2 = 0;
		For(i, 1, n) {
			if(b[i] > 0) sum1 += b[i];
			else sum2 -= b[i];
		}
		int tmp = min(sum1, sum2);
		sum1 -= tmp, sum2 -= tmp;
		return tmp * C + sum1 * B + sum2 * A;
	} else {
		For(i, 1, n) {
			if(b[i] > 0) ans += B * b[i];
			else ans += -A * b[i]; 
		}
	}
//	printf("%d\n", ans);
	return ans;
}
signed main()
{
	cin >> n >> A >> B >> C;
	For(i, 1, n) a[i] = read(), ckmin(l, a[i]), ckmax(r, a[i]); 
	sort(a + 1, a + 1 + n);
	int res = INF;    
	while(l <= r - 100) {
		int midl = l + (r - l) / 3, midr = r - (r - l) / 3;
		if(check(midl) > check(midr)) {
			l = midl;
		} else {
			r = midr;
		}
	}
	For(ans, l, r) {
		int t = check(ans);
		if(t < res) res = t;
	}
	cout << res << endl;
    return 0;
}