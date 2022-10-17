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
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
inline int read() {
    int num=0,flag=1;char c=' ';
    for(;!isdigit(c);c=getchar()) if(c=='-') flag=-1;
    for(;isdigit(c);num=num*10+c-48,c=getchar());
    return num*flag;
}
const int MAXN = 400005;
struct Line {
	int l, r;
	bool operator < (const Line b) const {return l != b.l ? l < b.l : r < b.r;}
}p[MAXN];
int disc[MAXN], dcnt = 0, n, m, K, t, used[MAXN], id[9][MAXN], ed[9][MAXN], mst[MAXN], mask[MAXN], f[2][1 << 9];
int siz[MAXN], adt[1 << 9];
void init() {
	sort(disc + 1, disc + 1 + dcnt);
	t = unique(disc + 1, disc + 1 + dcnt) - disc - 1;
	For(i, 1, n) {
		p[i].l = lower_bound(disc + 1, disc + 1 + t, p[i].l) - disc;
		siz[p[i].l] = disc[p[i].l] - disc[p[i].l-1];
		p[i].r = lower_bound(disc + 1, disc + 1 + t, p[i].r) - disc; 
		siz[p[i].r] = disc[p[i].r] - disc[p[i].r-1];
	}
	For(i, 1, t) siz[i] = disc[i] - disc[i-1];
}
signed main()
{
	cin >> n >> m >> K;
	For(i, 1, n)
		p[i].l = read(), p[i].r = read(), disc[++dcnt] = p[i].l, disc[++dcnt] = p[i].r, disc[++dcnt] = max(p[i].l - 1, 1);
	init();
	sort(p + 1, p + 1 + n);
//	For(i, 1, n)
//		printf("%d %d\n", p[i].l, p[i].r);
//	For(i, 1, t)
//		printf("%d\n", siz[i]);
//	printf("\n");
	For(i, 0, K-1) {
		int lst = 0, cnt = 0;
		For(j, 1, n) {
			if(!used[j] && p[j].l > lst) {
				lst = p[j].r; used[j] = 1; cnt++;
//				cout << j << ' ';
				For(k, p[j].l, p[j].r)
					id[i][k] = cnt;
				ed[i][p[j].r] = 1;
			}
		}
//		cout << endl;
	}
	
	For(j, 1, t)
		For(i, 0, K-1)
			mst[j] |= (1 << i) * (id[i][j] != 0), mask[j] |= (1 << i) * (ed[i][j] == 1);
//	For(i, 1, t) {
//		printf("%d\n", mst[i]);
//	}
//	puts("");
	For(i, 0, (1 << K) - 1) adt[i] = (__builtin_popcount(i) & 1);
	For(i, 1, t) {
		memset(f[i&1], 0, sizeof(f[i&1]));
		For(j, 0, (1 << K) - 1) {
			if((j | mst[i]) != mst[i]) continue;
			int lst = (j & mst[i-1]) & (mask[i-1] ^ mst[i-1]);
			for(int k = mask[i-1]; k; k = (k - 1) & mask[i-1])
				ckmax(f[i&1][j], f[(i&1)^1][lst | k] + adt[j] * siz[i]);
			ckmax(f[i&1][j], f[(i&1)^1][lst] + adt[j] * siz[i]) ; 
		}
//		For(j, 0, (1 << K) - 1) {
//			printf("%d ", f[i&1][j]);
//		}
//		printf("\n");
	} 
	int res = 0;
	For(j, 0, (1 << K) - 1) ckmax(res, f[t&1][j]);
	cout << res << endl;
    return 0;
}