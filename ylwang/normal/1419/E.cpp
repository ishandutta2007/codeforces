#pragma GCC optimize(3)
#pragma GCC optimize(2)
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
int p[MAXN], a[MAXN], pc, d[MAXN], dc = 0, used[MAXN], n;
void Div(int n) {
//	cerr << n << ":\n";
	For(i, 1, pc) p[i] = a[i] = 0; pc = 0; 
	For(i, 1, dc) used[i] = d[i] = 0; dc = 0;
	for(int i = 1; i * i <= n; i++) {
//		cerr << i << endl;
		if(n % i == 0) {
			if(n / i != i) d[++dc] = n / i;
			if(i != 1) d[++dc] = i;
		}
	}
	sort(d + 1, d + 1 + dc);
//	cerr << dc << endl;
//	cerr << "?";
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			p[++pc] = i;
			while(n % i == 0) {
				n /= i; a[pc]++;
			}
		}
	}
	if(n != 1)
		p[++pc] = n, a[pc] = 1;
//	cerr << pc << ' ' << dc << endl;
	
}
#define nxt(x) (x!=pc?x+1:1)
#define pre(x) (x!=1?x-1:pc)
void solve(int x) {
	For(i, 1, dc) {
		if(!used[i] && d[i] % p[x] == 0 && d[i] % p[nxt(x)] != 0 && (x != 1 || d[i] % p[pc] != 0)) printf("%d ", d[i]), used[i] = 1;
//		cerr << i << ' ' << d[i] << ' ' << p[pc] << endl;
//		cerr << x << ' ' << nxt(x) << ' ' << p[nxt(x)] << endl;
	}
    	
    For(i, 1, dc)
    	if(!used[i] && d[i] % p[x] == 0 && d[i] % p[nxt(x)] == 0 && (x != 1 || d[i] % p[pc] != 0)) printf("%d ", d[i]), used[i] = 1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    int T; cin >> T;
    while(T--) {
    	cin >> n;
    	Div(n);
    	if(pc == 1) {
    		For(i, 1, dc) printf("%d ", d[i]);
    		printf("\n0\n");
		} else if(pc == 2) {
			if(a[1] == 1 && a[2] == 1) {
	    		For(i, 1, dc)
	    			if(d[i] % p[1] == 0 && d[i] % p[2] != 0) printf("%d ", d[i]);
				For(i, 1, dc)
	    			if(d[i] % p[1] == 0 && d[i] % p[2] == 0) printf("%d ", d[i]);
	    		For(i, 1, dc)
	    			if(d[i] % p[1] != 0 && d[i] % p[2] == 0) printf("%d ", d[i]);
	    		printf("\n1\n");
			} else {
				For(i, 1, dc)
	    			if(d[i] % p[1] == 0 && d[i] % p[2] != 0) printf("%d ", d[i]);
				For(i, 1, dc)
	    			if(d[i] % p[1] == 0 && d[i] % p[2] == 0 && d[i] != p[2] * p[1]) printf("%d ", d[i]);
	    		For(i, 1, dc)
	    			if(d[i] % p[1] != 0 && d[i] % p[2] == 0) printf("%d ", d[i]);
	    		printf("%d\n0\n", p[2] * p[1]);
			}
    		
		} else {
			For(i, 1, pc) solve(i);
			printf("\n%d\n", 0);
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