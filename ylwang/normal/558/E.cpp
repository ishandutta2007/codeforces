#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
#define foR(i, k, j) for(rint i = (k); i >= (j); --i)
#define For(i, k, j) for(rint i = (k); i <= (j); ++i)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
//#define int long long
const int P = 998244353; //
using namespace std;
inline void ckmax(double &a, double b) {a = max(a, b);}
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
const int MAXN = 1e5 + 5;
int n, m;
char s[MAXN];
struct Segment_tree {
	int sum[MAXN<<2], tag[MAXN<<2];
	Segment_tree() {mst(sum, 0); mst(tag, -1);}
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void pushr(int k, int val, int l, int r) {
		sum[k] = val * (r - l + 1), tag[k] = val; 
	}
	void pushdown(int k, int l, int r) {
		if(tag[k] != -1) {
			pushr(ls, tag[k], l, mid);
			pushr(rs, tag[k], mid+1, r);
			tag[k] = -1;
		}
	}
	void update(int k, int l, int r, int ql, int qr, int val) {
//		cerr << k << ' ' << ql << ' ' << qr << ' ' <<l <<' ' << r  << ' ' <<val << endl;
		if(l == ql && r == qr) return sum[k] = val * (r - l + 1), tag[k] = val, void();
		pushdown(k, l, r);
		if(qr <= mid) update(ls, l, mid, ql, qr, val);
		else if(mid < ql) update(rs, mid+1, r, ql, qr, val);
		else update(ls, l, mid, ql, mid, val), update(rs, mid+1, r, mid+1, qr, val);
		sum[k] = sum[ls] + sum[rs];
	}
	int query(int k, int l, int r, int ql, int qr) {
//		cerr << "Q" << endl;
		if(l == ql && r == qr) return sum[k];
		pushdown(k, l, r);
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		if(mid < ql) return query(rs, mid+1, r, ql, qr);
		return query(ls, l, mid, ql, mid) + query(rs, mid+1, r, mid+1, qr);
	}
}tr[26];
void print() {
	For(i, 1, n) {
		For(j, 0, 25) {
			if(tr[j].query(1, 1, n, i, i)) {
				FO((char)(j + 'a')); 
//				cerr << (char) (j + 'a');
//				break;
			}
		}
	}
//	cerr << endl;
	FastIO::Fflush();
}
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n); FI(m);
	FI(s + 1);
	For(i, 1, n)
		tr[s[i]-'a'].update(1, 1, n, i, i, 1);
	while(m--) {
//		cerr << m << endl;
		int l, r, o, num[26];
		FI(l), FI(r), FI(o);
		For(i, 0, 25) num[i] = tr[i].query(1, 1, n, l, r);
		For(i, 0, 25) tr[i].update(1, 1, n, l, r, 0);
//		For(i, 0, 25) cerr << num[i] << ' ';
//		cerr << endl;
		int pos = l;
		if(o == 0) {
			foR(i, 25, 0) {
				if(!num[i]) continue;
				tr[i].update(1, 1, n, pos, pos + num[i] - 1, 1);
//				cerr << i <<' ' <<pos << endl;
				pos = pos + num[i];
			}
//			cerr << endl;
		} else  {
			For(i, 0, 25) {
				if(!num[i]) continue;
				tr[i].update(1, 1, n, pos, pos + num[i] - 1, 1);
				pos = pos + num[i];
			}
		}
		
//		print();
	}
	print();
    return FastIO::Fflush(), 0;
}
/*
LXRXLXL
*/