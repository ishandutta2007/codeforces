#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back // !
#define mkp make_pair
#define INF (1 << 30)
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
//#define int long long
const int P = 1000000007; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
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
const int MAXN = 80;
char s[MAXN]; int n, val[MAXN][MAXN], bit[MAXN], lb[MAXN];
inline int calc(int l, int r) {
	int v = 0;
	For(i, l, r) {
		v = (v << 1) + s[i] - '0';
		if(v >= 22) {
			v = INF; break;
		}
	}
	return v;
}
int f[MAXN][1<<20];
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n); FI(s + 1);
	For(i, 1, n) For(j, i, n)
		val[i][j] = calc(i, j);
//	For(i, 1, n) {
//		For(j, 1, n) cerr << val[i][j] << ' ';
//		cerr << endl;
//	}
	For(i, 1, n) foR(j, 5, 0) if((i >> j) & 1) {
		bit[i] = j + 1; break;
	}
	bit[0] = 1, lb[1] = 1;
	For(i, 2, n) {
		int now = 1; lb[i] = 1;
		while(now + bit[lb[i] + 1] <= i) {
			now += bit[lb[i] + 1]; lb[i]++;
		}
//		lb[i]++;
	}
//	For(i, 1, n) {
//		cerr << i << ' ' << lb[i] << endl;
//	}
	int res = 0;
	For(l, 1, n) { //  
//		cerr << l <<  ":" << endl;
		if(lb[n - l + 1] <= 18) {For(j, l - 1, n) For(s, 0, (1 << lb[n - l + 1]) - 1) if(f[j][s]) f[j][s] = 0;}
		else For(i, l - 1, n) mst(f[i], 0);
		f[l-1][0] = 1;
		For(i, l, n) {
			foR(j, i, l) {
//				cerr << j << ' ' << i << endl;
//				if(i > 1 && j > 1) assert(val[j][i] <= val[j-1][i]);
				if(val[j][i] > lb[n - l + 1]) break;
				if(!val[j][i]) continue;
				For(s, 0, (1 << lb[n - l + 1]) - 1)
					if((s >> (val[j][i] - 1)) & 1) addmod(f[i][s], (f[j-1][s] + f[j-1][s ^ (1 << (val[j][i] - 1))]) % P);
			}
		}
//		For(i, l, n) {
//			For(s, 0, (1 << lb[n - l + 1]) - 1) {
//				cerr << i << ' ' << s << ' ' << f[i][s] << endl;
//			}
//			cerr << endl;
//		}
		For(i, l, n) {
			For(j, 0, lb[i - l + 1]) {
				addmod(res, f[i][(1 << j) - 1]);
			}
		}
//		cerr << res << endl;
	}
	cout << res << endl;
    return FastIO::Fflush(), 0;
}
/*

75
101110001110011101110001110011101110001110011101110001110011101110001110011
*/