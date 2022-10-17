#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
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

inline void printarray(int *a, int n) {For(i, 1, n) fprintf(stderr, "%d ", a[i]); fprintf(stderr, "\n");}
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
const int MAXN = 3e5 + 5;
int n, a[MAXN], f[2][30];
struct Trie {
	int c[MAXN * 30][2], tot = 1;
	vector < int > g[MAXN * 30];
	#define ls c[p][0]
	#define rs c[p][1]
	void insert(int x, int tt) {
		int p = 1;
		foR(i, 29, 0) {
			int o = ((x >> i) & 1); 
			if(!c[p][o]) c[p][o] = ++tot;
			p = c[p][o]; g[p].pb(tt);
		}
	}
	void dfs(int p, int dep) {
//		cerr << p << ' ' << dep << endl;
		if(ls) dfs(ls, dep - 1);
		if(rs) dfs(rs, dep - 1);
		if(!ls || !rs) return;
		int res = 0, t = 0;
		for(auto it : g[ls]) {
//			cerr << it << endl;
			while(t < g[rs].size() && g[rs][t] < it) t++;
			res += t; 
		}
		f[0][dep] += res, f[1][dep] += 1ll * g[ls].size() * g[rs].size() - res;
	}
}tr;
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
	FI(n);
	For(i, 1, n) {
		int x; FI(x); 
		tr.insert(x, i);
	}   
	tr.dfs(1, 29);
	int t1 = 0, t2 = 0;
	For(i, 0, 29) {
		if(f[0][i] <= f[1][i]) t1 += f[0][i];
		else t1 += f[1][i], t2 += (1ll << i);
	}
	cout << t1 << ' ' << t2 << endl;
    return FastIO::Fflush(), 0;
}
/*

4 7 1
2 1 8
2 4 2
4 3 2
3 2 8
2 3 5
4 3 1
2 4 5
2 9
*/