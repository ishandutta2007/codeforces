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
//#define int long long
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
const int MAXN = 1e5 + 5;
int n, Qnum, a[MAXN]; 
const int P1 = 998244353, P2 = 1000000007;
struct Node {
	int x, y;
	Node operator + (const Node &b) {return (Node) {(x + b.x) % P1, (y + b.y) % P2};}
	Node operator + (const int &b) {return (Node) {(x + b) % P1, (y + b) % P2};}
	Node operator - (const Node &b) {return (Node) {(x - b.x + P1) % P1, (y - b.y + P2) % P2};}
	Node operator - (const int &b) {return (Node) {(x - b + P1) % P1, (y - b + P2) % P2};}
	Node operator * (const Node &b) {return (Node) {1ll * x * b.x % P1, 1ll * y * b.y % P2};}
	Node operator * (const int &b) {return (Node) {1ll * x * b % P1, 1ll * y * b % P2};}
	bool operator == (const Node &b) const {return x == b.x && y == b.y;}
	void print() {fprintf(stderr, "%d %d\n", x, y);}
};
const Node BASE = (Node) {131, 13331};
Node pw[MAXN], sum[10][MAXN];
struct Segment_tree {
	static const int N = MAXN << 2;
	Node Hash[N];
	int tag[N];
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	inline void pushr(int k, int v, int l, int r) {
		Hash[k] = sum[v][r-l+1], tag[k] = v;
	}
	inline void pushdown(int k, int l, int r) {
		if(tag[k] != -1) {
			pushr(ls, tag[k], l, mid);
			pushr(rs, tag[k], mid+1, r);
			tag[k] = -1;
		}
	}
	void build(int k, int l, int r) {
		if(l == r) return Hash[k] = (Node) {a[l], a[l]}, tag[k] = -1, void();
		build(ls, l, mid); build(rs, mid+1, r);
		Hash[k] = Hash[ls] * pw[r - mid] + Hash[rs], tag[k] = -1;
	}
	void update(int k, int l, int r, int ql, int qr, int v) {
		if(l == ql && r == qr) return pushr(k, v, l, r);
		pushdown(k, l, r);
		if(qr <= mid) update(ls, l, mid, ql, qr, v);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, v);
		else update(ls, l, mid, ql, mid, v), update(rs, mid+1, r, mid+1, qr, v);
		Hash[k] = Hash[ls] * pw[r - mid] + Hash[rs];
	}
	Node query(int k, int l, int r, int ql, int qr) {
		if(l == ql && r == qr) return Hash[k];
		pushdown(k, l, r);
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		if(mid < ql) return query(rs, mid+1, r, ql, qr);
		return query(ls, l, mid, ql, mid) * pw[qr - mid] + query(rs, mid+1, r, mid+1, qr);
	}
}tr;
signed main()
{
	#ifndef ONLINE_JUDGE 
		file("pro");
	#endif
	int t1, t2; cin >> n >> t1 >> t2; Qnum = t1 + t2;
	For(i, 1, n) scanf("%1d", &a[i]);
//	For(i, 1, n) cerr << a[i] << endl;
	pw[0] = (Node) {1, 1};
	For(i, 1, n) pw[i] = pw[i-1] * BASE;
	For(i, 0, 9) {
		sum[i][0] = (Node) {0, 0};
		For(j, 1, n)
			sum[i][j] = sum[i][j-1] * BASE + i;
//		For(j, 1, n) {
//			cerr << sum[i][j].x << ' ';
//		}
//		cerr << endl;
	}
	tr.build(1, 1, n);
	while(Qnum--) {
		int o, l, r, k; FI(o); FI(l); FI(r); FI(k);
		if(o == 1) {
			tr.update(1, 1, n, l, r, k);
		} else {
			if(r - l + 1 == k) {
				printf("YES\n"); continue;
			}
			Node x1 = tr.query(1, 1, n, l, r - k), x2 = tr.query(1, 1, n, l + k, r);
//			x1.print(), x2.print();
			printf(x1 == x2 ? "YES\n" : "NO\n");
		}
	}
    return FastIO::Fflush(), 0;
} 
/*
Think twice :
mod ?
INF ?
n = 1 ?
long long ?
Fastio::Fflush() ?
*/