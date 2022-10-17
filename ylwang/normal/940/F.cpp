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
#define INF ((1 << 30) - 1)
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
const int MAXN = 200005;
int n, m, a[MAXN], disc[MAXN], qn, cn, dn, Siz, ans[MAXN]; 
struct Query {
	int l, r, id, t;
	bool operator < (const Query b) {
		if(l / Siz != b.l / Siz) return l < b.l;
		if(r / Siz != b.r / Siz) return r < b.r;
		return t < b.t;
	}
}q[MAXN];
struct Modify {
	int pos, val; 
}c[MAXN];
int cnt[MAXN], tot[MAXN];
void add(int val) {
	tot[cnt[val]]--;
	tot[++cnt[val]]++;
}
void del(int val) {
	tot[cnt[val]]--;
	tot[--cnt[val]]++;
}
signed main()
{
	cin >> n >> m; dn = n, Siz = pow(n, 2.0 / 3);
	For(i, 1, n) disc[i] = a[i] = read();
	For(i, 1, m) {
		int op = read();
		if(op == 1)
			q[++qn].l = read(), q[qn].r = read(), q[qn].t = cn, q[qn].id = qn;  
		else
			c[++cn].pos = read(), disc[++dn] = c[cn].val = read();
	}
	sort(disc+1, disc+1+dn);
	dn = unique(disc+1, disc+1+dn) -  disc - 1;
	For(i, 1, n) a[i] = lower_bound(disc+1, disc+1+dn, a[i]) - disc;
	For(i, 1, cn) c[i].val = lower_bound(disc+1, disc+1+dn, c[i].val) - disc;
	sort(q + 1, q + 1 + qn);
	int l = 1, r = 0, t = 0;
	For(i, 1, qn) {
		int ql = q[i].l, qr = q[i].r, qt = q[i].t;
		while(r < qr) add(a[++r]);
		while(l > ql) add(a[--l]);
		while(l < ql) del(a[l++]);
		while(r > qr) del(a[r--]);
		while(t < qt) {
			t++; 
			if(ql <= c[t].pos && c[t].pos <= qr) {
				add(c[t].val);
				del(a[c[t].pos]);
				
			}
			swap(a[c[t].pos], c[t].val);
		}
		while(t > qt) {
			if(ql <= c[t].pos && c[t].pos <= qr) {
				add(c[t].val);
				del(a[c[t].pos]);
			}
			swap(a[c[t].pos], c[t].val);
			t--;
		}
		for(ans[q[i].id] = 1; tot[ans[q[i].id]] > 0; ans[q[i].id]++);
	} 
	For(i, 1, qn){
		printf("%d\n", ans[i]);
	}
    return 0;
}