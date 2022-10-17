#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define Pair pair < ll, ll >
#define mkp make_pair
#define rint register int
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG fprintf(stderr, "***IAKIOI***\n")
#define CDEBUG cerr << "***IAKIOI***" << endl;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin);freopen(s".out", "w", stdout)
#define INF ((1 << 30) - 1)
#define dprintf(x) fprintf(stderr, "%d ", x)
#define dprintfln(x) fprintf(stderr, "%d\n", x)
#define dln fprintf(stderr, "\n")
#define ull unsigned long long
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
const int MAXN = 200005;
int a[MAXN], n, P1 = 998244353, P2 = 1e9 + 7;
Pair BASE = mkp(15551, 1333331);
Pair operator + (Pair a, Pair b) {
	return mkp((a.first + b.first) % P1, (a.second + b.second) % P2);
} 
Pair operator - (Pair a, Pair b) {
	return mkp((a.first - b.first + P1) % P1, (a.second - b.second + P2) % P2);
}
Pair operator * (Pair a, Pair b) {
	return mkp((a.first * b.first) % P1, (a.second * b.second) % P2);
}
Pair operator + (Pair a, ull b) {
	return mkp((a.first + b) % P1, (a.second + b) % P2);
}
Pair pw[MAXN], H[MAXN][2];
int c[MAXN];
void init() {
	pw[0] = mkp(1, 1); 
	For(i, 1, n) pw[i] = pw[i-1] * BASE;
	For(i, 1, n) {
		if(a[i]) H[i][0] = H[i-1][0], H[i][1] = H[i-1][1], c[i] = c[i-1];
		else H[i][0] = H[i-1][0] * BASE + '0' + (i & 1), H[i][1] = H[i-1][1] * BASE + '0' + ((i & 1) ^ 1), c[i] = c[i-1] + 1;
	} 
	
}
Pair getHash(int l, int r, int op) {
	return H[r][op] - H[l-1][op] * pw[c[r] - c[l-1]];
}
signed main()
{
	srand(time(0));
	n = read();
	For(i, 1, n) {
		scanf("%1d", &a[i]);
	}
	init();
	int Q = read();
	while(Q--) {
		int l1 = read(), l2 = read(), len = read();
		int r1 = l1 + len - 1, r2 = l2 + len - 1;
		if(getHash(l1, r1, l1 & 1) == getHash(l2, r2, l2 & 1)) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}
/*

*/