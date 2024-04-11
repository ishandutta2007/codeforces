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
const int MAXN = 1e5 + 5;
int disc[MAXN], n, t, m, a[MAXN];
struct Query {
	int l, r;
}q[MAXN];
struct Segment_tree {
	int a[MAXN << 2], tag[MAXN << 2];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void update(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) {
			a[k] = (r - l + 1 - a[k]), tag[k] ^= 1;
			return void();
		}
		if(tag[k]) a[ls] = mid - l + 1 - a[ls], a[rs] = r - mid - a[rs], tag[ls] ^= 1, tag[rs] ^= 1, tag[k] = 0;
		if(qr <= mid) update(ls, l, mid, ql, qr);
		else if(ql > mid) update(rs, mid+1, r, ql, qr);
		else update(ls, l, mid, ql, mid), update(rs, mid+1, r, mid+1, qr);
		a[k] = a[ls] + a[rs];
	}
	int query(int k, int l, int r, int ql, int qr) {
//		cout << k << ' ' << l<< ' ' << r << ' '<< ql << ' ' << qr << ' ' << a[k] << ' ' << tag[k] << endl;
		if(ql > qr) return 0;
		if(l == ql && r == qr) return a[k];
		if(tag[k]) a[ls] = mid - l + 1 - a[ls], a[rs] = r - mid - a[rs], tag[ls] ^= 1, tag[rs] ^= 1, tag[k] = 0;
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		else if(ql > mid) return query(rs, mid+1, r, ql, qr);
		else return query(ls, l, mid, ql, mid) + query(rs, mid+1, r, mid+1, qr);
	}
}tr;
vector < int > l[MAXN], r[MAXN];
int sum[MAXN];
ll C(ll a, int b) {
	if(a < b) return 0;
	if(b == 3) return a * (a - 1) / 2 * (a - 2) / 3;
	if(b == 2) return a * (a - 1) / 2;
}
signed main()
{
	cin >> n >> m;
	For(i, 1, n) a[i] = read();
	sort(a + 1, a + 1 + n); 
	For(i, 1, n) disc[i] = a[i];
	For(i, 1, m) q[i].l = read(), q[i].r = read();
	t = unique(disc + 1, disc + 1 + n) - disc - 1;
	For(i, 1, m) {
		q[i].l = lower_bound(disc + 1, disc + 1 + t, q[i].l) - disc;
		int pos = lower_bound(disc + 1, disc + 1 + t, q[i].r) - disc;
		q[i].r = (a[pos] == q[i].r) ? pos : pos - 1;
	}
	For(i, 1, n) a[i] = lower_bound(disc + 1, disc + 1 + t, a[i]) - disc;
//	cout << t << endl;
//	For(i, 1, n) cout << a[i] << ' '; cout << endl;
//	For(i, 1, m) {
//		cout << q[i].l << ' ' << q[i].r << endl;
//	}
	
	For(i, 1, m)
		if(q[i].l <= q[i].r) l[q[i].l].pb(i), r[q[i].r].pb(i);
//	For(i, 1, t) {
//		sort(l[i].begin(), l[i].end());
//		sort(r[i].begin(), r[i].end());
//	}
//	cout << t << endl;
	int tmp = 0;
	For(i, 1, t) {
		for(auto v : r[i-1])
			tr.update(1, 1, t, q[v].l, q[v].r);
		for(auto v : l[i])
			tr.update(1, 1, t, q[v].l, q[v].r);
		if(a[tmp+1] == i)
			tmp++, sum[a[tmp]] = tmp - 1 - tr.query(1, 1, t, 1, a[tmp] - 1);
	}
//	For(i, 1, n) {
//		cout << sum[a[i]] << ' ';
//	}
//	cout << endl;
	memset(tr.a, 0, sizeof(tr.a)); memset(tr.tag, 0, sizeof(tr.tag)); 
	tmp = n+1;
	foR(i, t, 1) {
		for(auto v : r[i])
			tr.update(1, 1, t, q[v].l, q[v].r);
		for(auto v : l[i+1])
			tr.update(1, 1, t, q[v].l, q[v].r);
		if(a[tmp-1] == i) tmp--, sum[a[tmp]] += tr.query(1, 1, t, a[tmp] + 1, t);
//		cout << i << ' ' << tmp << ' ' << a[tmp] << ' ' << sum[a[tmp]] << endl;
	}
	ll res = C(n, 3);
//	For(i, 1, n) {
//		cout << sum[a[i]] << ' ';
//	}
//	cout << endl;
	For(i, 1, n)
		res -= C(sum[a[i]], 2);
	cout << res << endl; 
    return 0;
}