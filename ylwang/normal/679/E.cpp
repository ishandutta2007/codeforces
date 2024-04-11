#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back // !
#define mkp make_pair
#define rint register int
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
#define int long long
const int P = 998244353; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mul(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
inline void printarray(int *a, int n) {For(i, 1, n) fprintf(stderr, "%d ", a[i]); fprintf(stderr, "\n");}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 1e5 + 5, inf = 100000000000000000LL;
const int pw[] = {1LL, 42LL, 1764LL, 74088LL, 3111696LL, 130691232LL, 5489031744LL, 230539333248LL, 9682651996416LL, 406671383849472LL, 17080198121677824LL, 717368321110468608LL, 1000000000000000000LL};
inline int fpv(int x) { return *lower_bound(pw, pw + 12, x); }

int n, a[MAXN];
set < int > pos;
struct Segment_tree {
	static const int N = MAXN << 2;
	int nxt[N], mn[N], atag[N], dtag[N];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	inline void pushdown(int k) {
		if(atag[k]) {
			mn[ls] = mn[rs] = nxt[ls] = nxt[rs] = inf;
			dtag[ls] = dtag[rs] = atag[k] = 0;
			atag[ls] = atag[rs] = 1;
		}
		if(dtag[k]) {
			mn[ls] -= dtag[k], dtag[ls] += dtag[k];
			mn[rs] -= dtag[k], dtag[rs] += dtag[k];
			dtag[k] = 0;
		}
		
	}
	void modify(int k, int l, int r, int pos, int val) {
		if(l == r) return nxt[k] = fpv(val), mn[k] = nxt[k] - val, void();
		pushdown(k);
		pos <= mid ? modify(ls, l, mid, pos, val) : modify(rs, mid+1, r, pos, val);
		mn[k] = min(mn[ls], mn[rs]);
	}
	void assign(int k, int l, int r, int ql, int qr) {
//		cerr << "A" << ' ' << k << ' ' << l << ' ' << r << endl;
		if(l == ql && r == qr) return atag[k] = 1, mn[k] = nxt[k] = inf, dtag[k] = 0, void();
		pushdown(k);
		if(qr <= mid) assign(ls, l, mid, ql, qr);
		else if(mid < ql) assign(rs, mid+1, r, ql, qr);
		else assign(ls, l, mid, ql, mid), assign(rs, mid+1, r, mid+1, qr);
		mn[k] = min(mn[ls], mn[rs]);
	}
	void dec(int k, int l, int r, int ql, int qr, int v) {
//		cerr << "D" << ' ' << k << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
		if(l == ql && r == qr) return dtag[k] += v, mn[k] -= v, void();
		pushdown(k);
		if(qr <= mid) dec(ls, l, mid, ql, qr, v);
		else if(mid < ql) dec(rs, mid+1, r, ql, qr, v);
		else dec(ls, l, mid, ql, mid, v), dec(rs, mid+1, r, mid+1, qr, v);
		mn[k] = min(mn[ls], mn[rs]);
//		cerr << k << ' ' << mn[k] << ' ' << mn[ls] << ' ' << mn[rs] << endl;
	}
	int getval(int k, int l, int r, int pos) {
		if(l == r) {
			assert(nxt[k] != inf);
			return nxt[k] - mn[k];
		}
		pushdown(k);
		return pos <= mid ? getval(ls, l, mid, pos) : getval(rs, mid+1, r, pos);
	}
	void print(int k, int l, int r) {
		fprintf(stderr, "%lld %lld %lld %lld %lld %lld %lld\n", k, l, r, nxt[k], mn[k], atag[k], dtag[k]); 
		if(l == r) return;
		print(ls, l, mid), print(rs, mid+1, r);
	}
	int print() {
		print(1, 1, n); fprintf(stderr, "\n");
	}
	int query(int k, int l, int r, int ql, int qr) {
//		cerr << "Q" << ' ' << k << ' ' << l << ' ' << r << endl;
		if(l == ql && r == qr) {
			if(mn[k] >= 0) return mn[k];
			if(l == r) {
				int val = nxt[k] - mn[k];
				nxt[k] = fpv(val), mn[k] = nxt[k] - val;
				return mn[k];
			}
			pushdown(k);
			if(mn[ls] < 0 && mn[rs] < 0)
				query(ls, l, mid, ql, mid), query(rs, mid+1, r, mid+1, qr);
			else if(mn[ls] < 0) query(ls, l, mid, ql, mid);
			else query(rs, mid+1, r, mid+1, qr);
			return mn[k] = min(mn[ls], mn[rs]);
		}
		pushdown(k);
		if(qr <= mid) query(ls, l, mid, ql, qr);
		else if(mid < ql) query(rs, mid+1, r, ql, qr);
		else query(ls, l, mid, ql, mid), query(rs, mid+1, r, mid+1, qr);
		return mn[k] = min(mn[ls], mn[rs]);
	}
}tr;
inline void split(int x) {
	int t = *pos.lower_bound(x);
	if(t == x) return; 
//	cerr << x << ' ' << t << endl;
	pos.insert(x);
	if(!tr.getval(1, 1, n, t)) {
		cout << "Wrong on t : " << t << endl;
		exit(0);
	}
	tr.modify(1, 1, n, x, tr.getval(1, 1, n, t));
}
signed main()
{
	#ifndef ONLINE_JUDGE 
		file("pro");
	#endif
	int Qnum; 
	FI(n); FI(Qnum);
	
	For(i, 1, n) FI(a[i]), pos.insert(i);
	For(i, 1, n) tr.modify(1, 1, n, i, a[i]);
//	tr.print();
//	cerr << fpv(1764) << endl;
//	For(i, 1, n) {
//		cerr << fpv(a[i]) << endl;
//	}
	while(Qnum--) {
		int o, l, r, v; FI(o);
		if(o == 1) {
			FI(v);
//			cerr << v << ' ' << (*pos.lower_bound(v)) << endl;
			assert(*pos.lower_bound(v) <= n);
			FO(tr.getval(1, 1, n, *pos.lower_bound(v))); FO('\n');
		} else {
			FI(l); FI(r); FI(v);
			if(l > 1) split(l - 1);
			split(r);
			if(o == 2) {
				pos.erase(pos.lower_bound(l), pos.lower_bound(r));
				if(l < r) tr.assign(1, 1, n, l, r - 1);
				tr.modify(1, 1, n, r, v);
			} else {
				tr.dec(1, 1, n, l, r, v);
//				int t = tr.query(1, 1, n, l, r);
//				cerr << t << endl;
				while(!tr.query(1, 1, n, l, r))
					tr.dec(1, 1, n, l, r, v);
			}
		}
//		tr.print();
	}
	
    return FastIO::Fflush(), 0;
}