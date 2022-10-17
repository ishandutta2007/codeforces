#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
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
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}

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
int n, Q, rev[20];
struct Segment_tree {
	int sum[MAXN<<2];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void update(int d, int k, int l, int r, int pos, int val) {
		if(l == r) return sum[k] = val, void();
		if(pos <= mid) {
			update(d - 1, !rev[d] ? ls : rs, l, mid, pos, val); 
		} else {
			update(d - 1, !rev[d] ? rs : ls, mid + 1, r, pos, val); 
		}
		sum[k] = sum[ls] + sum[rs];
	}
	int query(int d, int k, int l, int r, int ql, int qr) {
//		cerr << k << ' ' << l <<  ' ' << r << ' ' << ql << ' ' << qr << endl; 
		if(l == ql && r == qr) return sum[k];
		if(qr <= mid) return query(d - 1, !rev[d] ? ls : rs, l, mid, ql, qr);
		if(mid < ql) return query(d - 1, !rev[d] ? rs : ls, mid+1, r, ql, qr);
		return query(d - 1, !rev[d] ? ls : rs, l, mid, ql, mid) + query(d - 1, !rev[d] ? rs : ls, mid+1, r, mid+1, qr);
	}
}tr;
signed main()
{
	#ifndef ONLINE_JUDGE 
		file("pro");
	#endif
	cin >> n >> Q;
	For(i, 1, 1 << n) {
		int x; FI(x);
		tr.update(n, 1, 1, 1 << n, i, x);
	}
	while(Q--) {
		int op, x, k;
		FI(op); 
		if(op == 1) {
			FI(x); FI(k);
			tr.update(n, 1, 1, 1 << n, x, k);
		}
		if(op == 2) {
			FI(k);
			For(i, 0, k) rev[i] ^= 1;
		} 
		if(op == 3) {
			FI(k);
			rev[k + 1] ^= 1;
		}
		if(op == 4) {
			FI(x); FI(k);
			printf("%lld\n", tr.query(n, 1, 1, 1 << n, x, k));
		}
	}
    return FastIO::Fflush(), 0;
}