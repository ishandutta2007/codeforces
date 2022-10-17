#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
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
//#define int long long
const int P = 998244353;
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
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int MAXN = 3005;
int n, c, a[MAXN];
namespace small {
	int f[2][MAXN][1 << 12], ans[MAXN], C[MAXN][MAXN];
	int main() {
		if(c == 1) {
			C[0][0] = 1;
			For(i, 1, n) {
				For(j, 0, i)
					C[i][j] = (j ? C[i-1][j-1] + C[i-1][j] : 1) % P;
			}
			printf("0 ");
			For(i, 1, n) {
				printf("%d ", C[n][i]);
			}
			return 0;
		}
		f[0][0][0] = 1;
		For(i, 1, n) a[i]--;
		For(now, 0, n - 1) {
			int i = now & 1;
			For(j, 0, now / c + 1) {
				For(st, 0, (1 << c) - 1) {
					if((st | (1 << a[now + 1])) == ((1 << c) - 1)) addmod(f[i ^ 1][j + 1][0], f[i][j][st]);
					else addmod(f[i ^ 1][j][st | (1 << a[now + 1])], f[i][j][st]);
					addmod(f[i ^ 1][j][st], f[i][j][st]);
				}
			}
			For(j, 0, now / c)
				mst(f[i][j], 0);
			
		}
		ans[0] = -1;
		For(i, 0, n)
			For(st, 0, (1 << c) - 1)
				addmod(ans[i], f[n & 1][i][st]);
		For(i, 0, n) printf("%d ", ans[i]);
		return 0;
	}
} 
namespace large {
	int f[MAXN][MAXN], g[MAXN][MAXN], h[MAXN], cnt[MAXN], p2[MAXN], im[MAXN], ans[MAXN];
	int main() {
		p2[0] = 1; For(i, 1, n) p2[i] = p2[i - 1] * 2 % P, im[i] = inv(p2[i] - 1);
		a[n + 1] = c + 1;
		For(i, 1, n + 1) {
			mst(cnt, 0);
			cnt[a[i]] = 1; int t = c - 1;
			g[i][i] = 1;
			for(int j = i - 1; j >= 1; j--) {
				int para = 1;
				if(a[j] != a[i]) {
					if(cnt[a[j]]) mulmod(para, im[cnt[a[j]]]);
					cnt[a[j]]++; mulmod(para, p2[cnt[a[j]]] - 1);
				}
//				cerr << i << ' ' << j << ' ' << para << endl;
				g[j][i] = 1ll * g[j + 1][i] * para % P;
			}
			mst(cnt, 0); g[i][i] = 0; if(i == n + 1) t++;
			for(int j = i - 1; j >= 1; j--) {
				if(a[j] != a[i]) {
					if(!cnt[a[j]]) t--;
					cnt[a[j]]++;
				}
//				cerr << i << ' ' << j << ' ' << t << endl;
				if(t) g[j][i] = 0;
				else break;
			}
			if(i == n + 1) {
				For(j, 1, i)
					h[j] = (p2[i - j] - g[j][i] + P) % P;
			}
			
		}
//		For(i, 1, n) {
//			For(j, i, n) {
//				cerr << i << ' ' << j << ' ' << g[i][j] << endl;
//			} 
//		}
//		For(i, 1, n + 1) cerr << h[i] << ' ';
//		cerr << endl;
		f[0][0] = 1;
		For(i, 1, n) {
			For(j, 0, i / c) {
				For(k, 0, i - 1) {
					if(!g[k + 1][i]) break;
					addmod(f[i][j], 1ll * f[k][j - 1] * g[k + 1][i] % P);
				}
				if(j != 0 && f[i][j] == 0) break;
			}
		}
		For(i, 0, n)
			For(j, 0, n / c)
				addmod(ans[j], 1ll * f[i][j] * h[i + 1] % P);
		ans[0] = (ans[0] + P - 1) % P;
		For(i, 0, n) {
			printf("%d ", ans[i]);
		}
		return 0;
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE 
		file("pro");
    #endif
	n = read(), c = read();
	For(i, 1, n) a[i] = read();
	if(c <= 12) return small::main();
	else return large::main();   
    
    return FastIO::Fflush(), 0;
}
/*
Ivan 
*/