#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(int i = (k); i >= (j); i--)
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
#define int long long
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
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(ll x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int N = 60;
int c[N], bas = 1, n, m;
inline void insert(int x) {
	for(int i = m - 1; i >= 0; i--) {
		if(!(x >> i & 1)) continue;
		if(!c[i]) {
			c[i] = x; break;
		} else x ^= c[i];
	}
}
inline void getbas() {
	int res = n;
	For(i, 0, m - 1) res -= c[i] > 0;
	For(i, 1, res) bas = bas * 2 % P;
} 
const int MD2 = 1 << 19 | 1;
int f[MD2], g[20][MD2], h[MD2], ans[N];
#define pcnt(i) __builtin_popcount(i)
const int inv2 = (P + 1) >> 1;
int add(int p, int q) {
	return (p + q) >= P ? (p + q - P) : p + q;
}
int del(int p, int q) {
	return (p - q) < 0 ? (p - q + P) : (p - q);
}
void fwt(int *a, int n, int o = 1) {
	n = 1 << n;
	for(int k = 1; k < n; k <<= 1)
		for(int i = 0; i < n; i += k << 1)
			for(int j = 0; j < k; j++) {
				int p = a[i + j], q = a[i + j + k], x = i + j, y = i + j + k;
				if(o == 1) a[x] = add(p, q), a[y] = del(p, q);
				else a[x] = 1ll * add(p, q) * inv2 % P, a[y] = 1ll * del(p, q) * inv2 % P;
			}
}
signed main()
{
	#ifndef ONLINE_JUDGE 
    	file("pro");
    #endif
    n = read(), m = read();
    For(i, 1, n) insert(read());
	getbas();
	For(st, 0, (1 << m / 2) - 1) {
		int tmp = 0;
		For(i, 0, m / 2 - 1)
			if(st >> i & 1) tmp ^= c[i];
		f[tmp]++;
	}
	For(st, 0, (1 << (m - m / 2)) - 1) {
		int tmp = 0, cnt = 0;
		For(i, 0, (m - m / 2) - 1)
			if(st >> i & 1) tmp ^= c[i + m / 2];
		cnt = pcnt(tmp >> m / 2);
		g[cnt][tmp & ((1 << (m / 2)) - 1)]++;
	}
	fwt(f, (m + 1) / 2);
	For(i, 0, m - m / 2) {
		fwt(g[i], (m + 1) / 2);
		For(j, 0, (1 << (m + 1) / 2) - 1) h[j] = 1ll * f[j] * g[i][j] % P;
		fwt(h, (m + 1) / 2, -1);
		For(j, 0, (1 << (m + 1) / 2) - 1) addmod(ans[pcnt(j) + i], h[j]);
	}
	For(i, 0, m) {
		if(n > m) printf("%lld ", 1ll * ans[i] * ksm(2, n - m)% P);
		else printf("%lld ", 1ll * ans[i] * inv(ksm(2, -n + m)) % P);
	}
    return FastIO::Fflush(), 0;
}
/*
ai - s3x^2 + 3x - 1
*/