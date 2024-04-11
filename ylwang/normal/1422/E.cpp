#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1ll << 62) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Fin(s) freopen(s, "r", stdin)
#define Fout(s) freopen(s, "w", stdout)
#define file(s) Fin(s".in"), Fout(s".out")
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
inline int read() {int x; FI(x); return x;}
const int MAXN = 2e5 + 20;
const int P1 = 998244853, P2 = 1000000007;
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
char s[MAXN]; int n, nxt[MAXN][19], len[MAXN], to[MAXN];
Node pw[MAXN], Hash[MAXN][19];
inline void init() {
	pw[0] = (Node) {1, 1}; For(i, 1, n) pw[i] = pw[i - 1] * BASE;
}
bool cmp(int i, int j) {
//	cerr << "cmp " << i << ' ' << j << endl;
	i = to[i], j = to[j];
	for(int k = 18; k >= 0; k--)
		if((nxt[i][k] || nxt[j][k]) && Hash[i][k] == Hash[j][k]) i = nxt[i][k], j = nxt[j][k];
	return s[i] < s[j];
}
void upd(int i, int j, char c) {
//	cerr << "upd " << i << ' ' << j << ' ' << c << endl;
	if(c == '&') {
		to[i] = to[j]; len[i] = len[to[i]];
	} else {
		to[i] = i; Hash[i][0] = (Node) {c, c}, nxt[i][0] = to[j];
		i == n ? len[i] = 1 : len[i] = len[to[j]] + 1;
		for(int k = 1; k <= 18 && i + (1 << k) <= n; k++) {
			Hash[i][k] = Hash[i][k - 1] * pw[1 << (k - 1)] + Hash[nxt[i][k - 1]][k - 1];
			nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
		}
	}
}
void print(int x) {
	printf("%d ", len[x]);
	x = to[x];
	if(len[x] <= 10) {
		for(int i = 1; i <= 10 && x; i++) {
			printf("%c", s[x]); x = nxt[x][0];
		}
	} else {
		
		for(int i = 1; i <= 5 && x; i++) {
			printf("%c", s[x]); x = nxt[x][0];
		}
		printf("...");
		int d = len[x] - 2;
		for(int i = 18; i >= 0; i--) {
			if((1 << i) <= d) {
//				cerr << i << ' ' << x << ' ';
				d -= (1 << i);
				x = nxt[x][i];
//				cerr << x << endl;
			}
		}
		printf("%c%c", s[x], s[nxt[x][0]]);
	}
//	cerr << endl;
	printf("\n");
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(s + 1); n = strlen(s + 1);
    init();
    for(int i = n; i >= 1; i--) {
    	upd(i, i + 1, s[i]);
    	if(i < n && s[i] == s[i + 1] && cmp(i + 2, i))
    		upd(i, i + 2, '&');
	}
//	For(i, 1, n) cerr << nxt[i][0] << ' '; cerr << endl;
//	For(i, 1, n) cerr << nxt[i][1] << ' '; cerr << endl;
//	For(i, 1, n) cerr << nxt[i][2] << ' '; cerr << endl;
	
	for(int i = 1; i <= n; i++) 
		print(i);
	
    return FastIO::Fflush(), 0;
}
/*

*/