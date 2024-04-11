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
//#define int long long
const int P = 998244353; //
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
int n, m, k;
struct oLim {
	int l, r, x;
}lim[MAXN];

int l[MAXN], a[MAXN], f[MAXN];
int solve() {
	For(i, 1, n + 1) a[i] += a[i-1], ckmax(::l[i], ::l[i-1]);
//	For(i, 1, n) {
//		cerr << a[i] << ' ' << ::l[i] << endl;
//	}
//	cerr << endl;
	int l = 0, sum = 1; ::l[n + 1] = 0, f[0] = 1;
	For(i, 1, n + 1) {
		if(a[i]) f[i] = 0;
		else {
			while(l < ::l[i - 1]) sum = (sum - f[l] + P) % P, l++;
			f[i] = sum; sum = (sum + f[i]) % P;
		}
//		cerr << a[i] << ' ' << f[i] << ' ' << ::l[i] << endl;
		
	}
//	cerr << f[n + 1] << endl;
	return f[n + 1];
}
signed main()
{
	#ifndef ONLINE_JUDGE 
		file("pro");
	#endif
	FI(n); FI(k); FI(m);
	For(i, 1, m) {
		FI(lim[i].l), FI(lim[i].r),  FI(lim[i].x);
	}
	int res = 1;
	For(j, 0, k - 1) {
		For(i, 0, n) l[i] = 0, a[i] = f[i] = 0;
		For(i, 1, m) {
			if((lim[i].x >> j) & 1) {
				a[lim[i].l]++; a[lim[i].r+1]--;
			} else {
				ckmax(l[lim[i].r], lim[i].l);
			}
		}
		
		res = 1ll * res * solve() % P;
		if(!res) break;
	}
	cout << res << endl;
    return FastIO::Fflush(), 0;
}