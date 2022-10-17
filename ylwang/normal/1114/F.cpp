#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back // !
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
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
const int P = 1000000007; //
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
const int MAXN = 5e5 + 5;
const int MAXA = 305 + 5;
int a[MAXN], n, Qnum, d[MAXA], prime[MAXA], cnt = 0, vis[MAXA], v[MAXA];
void init(int n) {
	For(i, 2, n) {
		if(!vis[i]) prime[cnt++] = i;
		for(int j = 0; j < cnt && i * prime[j] <= n; j++) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	mst(d, 0);
//	cerr << cnt << endl;
	For(i, 0, cnt - 1)
		for(int j = 1; j * prime[i] <= n; j++)
//			cerr << i << ' ' << j << ' ' << j * prime[i] << endl;
			d[j * prime[i]] |= (1ll << i);
			
//	For(i, 1, 10) {
//		cerr << d[i] << endl; 
//	}
	For(i, 0, cnt - 1)
		v[i] = 1ll * (prime[i] - 1) * inv(prime[i]) % P;
//	For(i, 0, cnt - 1) {
//		cerr << prime[i] << ' ' << v[i] << endl;
//	}
}

struct Segment_tree {
	static const int N = MAXN << 2;
	int mul[N], st[N], tag[N], stag[N];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	Segment_tree() {For(k, 0, N-2) mul[k] = tag[k] = 1, st[k] = stag[k] = 0;}
	inline void pushr(int k, int v1, int v2, int l, int r) {
		mul[k] = 1ll * mul[k] * ksm(v1, r - l + 1) % P, tag[k] = 1ll * tag[k] * v1 % P;
		st[k] |= v2, stag[k] |= v2;
	}
	inline void pushdown(int k, int l, int r) {
		if(tag[k] != 1) {
			pushr(ls, tag[k], stag[k], l, mid);
			pushr(rs, tag[k], stag[k], mid + 1, r);
			tag[k] = 1, stag[k] = 0;
		}
	}
	inline void update(int k, int l, int r, int ql, int qr, int v) {
//		cerr << k << ' ' << l << ' ' << r << ' ' << v << endl;
		if(l == ql && r == qr) return pushr(k, v, d[v], l, r);
		pushdown(k, l, r);
		if(qr <= mid) update(ls, l, mid, ql, qr, v);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, v);
		else update(ls, l, mid, ql, mid, v), update(rs, mid+1, r, mid+1, qr, v);
		mul[k] = 1ll * mul[ls] * mul[rs] % P, st[k] = st[ls] | st[rs];
	}
	int query_mul(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return mul[k];
		pushdown(k, l, r);
		if(qr <= mid) return query_mul(ls, l, mid, ql, qr);
		if(mid < ql ) return query_mul(rs, mid+1, r, ql, qr);
		return 1ll * query_mul(ls, l, mid, ql, mid) * query_mul(rs, mid+1, r, mid+1, qr) % P;
	}
	int query_st(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return st[k];
		pushdown(k, l, r);
		if(qr <= mid) return query_st(ls, l, mid, ql, qr);
		if(mid < ql ) return query_st(rs, mid+1, r, ql, qr);
		return query_st(ls, l, mid, ql, mid) | query_st(rs, mid+1, r, mid+1, qr);
	}
}tr;
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	init(300);
	FI(n); FI(Qnum);
	For(i, 1, n) FI(a[i]);
	For(i, 1, n)
		tr.update(1, 1, n, i, i, a[i]);
	while(Qnum--) {
		char op[55]; int l, r; 
		FI(op); FI(l); FI(r);
		if(op[0] == 'M') {
			int v; FI(v);
			tr.update(1, 1, n, l, r, v);
		} else {
			int res = tr.query_mul(1, 1, n, l, r), st = tr.query_st(1, 1, n, l, r);
//			cerr << res << ' ' << st << endl;
			For(i, 0, cnt - 1) {
				if((st >> i) & 1) {
					res = 1ll * res * v[i] % P;
				}
			}
			FO(res); FO('\n');
		}
	}
    return FastIO::Fflush(), 0;
}
/*
1 1
36
2 1
*/