#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define ull unsigned ll
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
const int P = 998244353; //
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
const int MAXN = 105;
const int MAXS = (1 << 15) + 5;
int n, a[MAXN], c[MAXN], d[MAXN][20], p[MAXN];
bool operator < (const vector < int > & a, const vector < int > & b) {
	int n = a.size(), m = b.size();
	if(n != m) return n < m;
	For(i, 0, n - 1)
		if(a[i] != b[i]) return a[i] < b[i];
	return 0;
}
map < vector < int >, int > mp; 
inline void print(vector < int > x) {
	for(auto v : x) {
		cerr << v  << ' ';
	}
	cerr << endl;
}
signed main()
{
	#ifndef ONLINE_JUDGE
		file("pro");
	#endif
	FI(n); For(i, 1, n) FI(a[i]);
	For(i, 1, n) c[i] = __builtin_popcount(a[i] >> 15);
	For(i, 1, n) {
		For(j, 0, 15) {
			if((a[i] >> (j + 15)) & 1) d[i][j] = -1;
			else d[i][j] = 1;
		}
	}
//	For(i, 1, n) cerr << c[i] << endl;
	For(st, 0, (1 << 15) - 1) {
		For(i, 1, n) p[i] = c[i]; vector < int > tmp; tmp.clear();
		For(j, 0, 15) {
			if(!((st >> j) & 1)) continue;
			For(i, 1, n)
				p[i] += d[i][j];
		} 
		For(i, 1, n) tmp.pb(p[i]);
//		if(st <= 8) {
//			cerr << st << endl;
//			print(tmp);
//		}
		mp[tmp] = st;
	}
//	cerr << endl;
	For(i, 1, n) c[i] = __builtin_popcount(a[i]) - __builtin_popcount(a[i] >> 15);
	For(i, 1, n) {
//		cerr << a[i] << endl;
		For(j, 0, 15) {
			if((a[i] >> j) & 1) d[i][j] = -1;
			else d[i][j] = 1;
		}
	}
	For(st, 0, (1 << 15) - 1) {
		For(i, 1, n) p[i] = c[i]; vector < int > tmp; tmp.clear();
		For(j, 0, 15) {
			if(!((st >> j) & 1)) continue;
			For(i, 1, n)
				p[i] += d[i][j];
		} 
//		cerr << st << endl;
//		For(i, 1, n) cerr << p[i] << ' ';
//		cerr << endl;
		For(ans, 0, 30) {
			tmp.clear();
			For(i, 1, n) tmp.pb(ans - p[i]);
			if(mp.count(tmp)) {
//				print(tmp);
//				cerr << mp[tmp] << ' ' << st << endl;
				printf("%d\n", (mp[tmp] << 15) + st);
				exit(0);
			}
		}
	}
	printf("-1\n");
	
    return FastIO::Fflush(), 0;
}
/*

*/