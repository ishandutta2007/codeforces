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
#define int long long
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
const int MAXN = 240005;
int n, m, a[MAXN], ql[MAXN], res[MAXN];
struct Node {int x, y;};
vector < Node > q[MAXN];
struct Segment_tree {
	int mn[MAXN<<2], cnt[MAXN<<2], am[MAXN<<2], sum[MAXN << 2], as[MAXN<<2];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r)>>1)
	void pushdown(int k)  {
		if(am[k]) {
			mn[ls] += am[k], am[ls] += am[k];
			mn[rs] += am[k], am[rs] += am[k];
			am[k] = 0;
		}
		if(as[k]) {
			if(mn[ls] == mn[k]) sum[ls] += as[k] * cnt[ls], as[ls] += as[k];
			if(mn[rs] == mn[k]) sum[rs] += as[k] * cnt[rs], as[rs] += as[k];
			as[k] = 0;
		}
		
	}
	void pushup(int k) {
		mn[k] = min(mn[ls], mn[rs]);
//		cout << "***" << mn[ls] << ' ' << mn[rs] << ' ' << mn[k] << endl;
		if(mn[ls] == mn[rs]) cnt[k] = cnt[ls] + cnt[rs];
		else cnt[k] = mn[ls] < mn[rs] ? cnt[ls] : cnt[rs];
		sum[k] = sum[ls] + sum[rs];
	}
	void build(int k, int l, int r) {
		mn[k] = l; cnt[k] = 1;
		if(l == r) {return;}
		build(ls, l, mid); build(rs, mid+1, r);
	}
	void print(int k, int l, int r) {
		printf("%d %d %d %d %d %d\n", k, l, r, mn[k], cnt[k], am[k]);
		if(l == r) return; 
//		pushdown(k);
		print(ls, l, mid); print(rs, mid+1, r);
	}
	inline void update(int k, int l, int r, int ql, int qr, int val) {
//		cout << k << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << endl; 
		if(l == ql && r == qr) {mn[k] += val, am[k] += val; return;}
		pushdown(k);
		if(qr <= mid) update(ls, l, mid, ql, qr, val);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, val);
		else { update(ls, l, mid, ql, mid, val), update(rs, mid+1, r, mid+1, qr, val);}
		pushup(k);
	}
	inline int query(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return sum[k]; pushdown(k);
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		else if(mid < ql) return query(rs, mid+1, r, ql, qr);
		else return query(ls, l, mid, ql, mid) + query(rs, mid+1, r, mid+1, qr);
	}
}t;
stack < int > s1, s2;
signed main()
{
	cin >> n;
	For(i, 1, n) a[i] = read();
	cin >> m;
	For(i, 1, m) {
		int l = read(), r = read();
		q[r].pb((Node) {i, l});
	}
	t.build(1, 1, n);
	s1.push(0); s2.push(0);
	For(i, 1, n) {
		t.mn[1]--, t.am[1]--;
//		cout << "?" << endl;
		while(s1.size() > 1 && a[s1.top()] < a[i]) {
			int tt = s1.top(); s1.pop();
			
			t.update(1, 1, n, s1.top() + 1, tt, a[i] - a[tt]);
		}
		s1.push(i);
		while(s2.size() > 1 && a[s2.top()] > a[i]) {
			int tt = s2.top(); s2.pop();
			t.update(1, 1, n, s2.top() + 1, tt, a[tt] - a[i]);
//			cout << i << ' ' << s2.top() + 1 << ' ' << tt << endl;
		}
		s2.push(i);
		
		t.sum[1] += t.cnt[1], t.as[1]++;
		
		for(auto v : q[i]) {
			int id = v.x, l = v.y;
			res[id] = t.query(1, 1, n, l, i);
		}
//		t.print(1, 1, n);
//		cout << t.cnt[1] << ' ' << t.mn[1] << endl;
//		printf("\n\n");
	}
	For(i, 1, m) {
		printf("%lld\n", res[i]);
	}
    return 0;
}