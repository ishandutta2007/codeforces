#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define si set < int >
#define vi vector < int >
#define pii pair < int, int >
#define mii map < int, int >
#define p_q priority_queue
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(int i = (k); i >= (j); i--)
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define Foe(i, u) for(int i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
#define int long long
const int P = 1e9 + 7; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline void submod(int &a, int b) {int t = a - b; a = (t < 0 ? t + P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int MAXN = 4005, MAXK = 705; 
int n, K, a[MAXN][MAXN], s[MAXN][MAXN]; pii f[MAXN];
#define calc(i, j) (f[j].first + (s[i][i] - s[i][j] * 2 + s[j][j]) / 2 + T)
struct ele {ele(){}; ele(int L, int R, int V) : l(L), r(R), v(V) {}int l, r, v;} q[MAXN]; int h, t;
pii check(int T) {
	For(i, 1, n) f[i].first = INF; f[0] = mkp(0, 0);
	h = 1, q[t = 1] = ele(1, n, 0);
	For(i, 1, n) {
//		cerr << i << endl;
		if(i > q[h].r) h++; f[i] = mkp(calc(i, q[h].v), f[q[h].v].second + 1);
		while(h <= t && calc(q[t].l, i) <= calc(q[t].l, q[t].v)) t--;
		if(h <= t) {
			int l = q[t].l, r = q[t].r, pos = q[t].r + 1;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(calc(mid, i) <= calc(mid, q[t].v)) pos = mid, r = mid - 1;
				else l = mid + 1;
			}
			if(pos != q[t].r + 1) {
				ele tmp = q[t--];
				q[++t] = ele(tmp.l, pos - 1, tmp.v);
			}
			if(pos <= n) q[++t] = ele(pos, n, i);	
		} else q[++t] = ele(i+1, n, i);
		ckmax(q[h].l, i+1);
	}
	return f[n];
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    n = read(), K = read();
    For(i, 1, n) For(j, 1, n) a[i][j] = read(), s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
//    For(i, 1, n) {
//    	For(j, 1, n) {
//			cerr << s[i][j] << ' ';
//		}
//		cerr << endl;
//    }
//	check(100);
	int l = 0, r = 2e9, ans = 0, t = 0; pii tmp;
	while(l <= r) {
		int mid = (l + r) >> 1; tmp = check(mid);
		if(tmp.second >= K) { t = mid, l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	tmp = check(t);
	printf("%lld\n", tmp.first - K * t);
    return FastIO::Fflush(), 0;
}