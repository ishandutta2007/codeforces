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
const int MAXN = 1e6 + 5;
char s[MAXN]; int n, pos[MAXN], m, a[MAXN], f[MAXN];
bool c(int l, int r) {
	if(l > r - 1) return 1;
	return a[min(r - 1, n)] - a[max(l, 0)] <= 0;
}
int check(int mid) {
//	cerr << "mid = " << mid <<  endl;
	mst(f, 0);
	f[0] = -mid;
	For(i, 1, m) {
		if(c(f[i - 1], pos[i] - mid)) ckmax(f[i], pos[i]);
		if(c(f[i - 1], pos[i])) ckmax(f[i], pos[i] + mid);
		if(i > 1) {
			if(c(f[i - 2], pos[i] - mid)) ckmax(f[i], pos[i - 1] + mid);
		}
//		cerr << i << ' ' << f[i] << endl;
		if(f[i] >= n) return 1;
	}
	
	return c(f[m], n + 1);
}
signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    FI(n); FI(s + 1);
    For(i, 1, n) {
    	a[i] = a[i - 1] + (s[i] == '*');
    	if(s[i] == 'P') pos[++m] = i;
	}
	if(m == 1) {
		int lst = INF, pre = -INF;
		For(i, pos[1], n) if(pos[1] <= i && s[i] == '*') lst = i;
		foR(i, pos[1], 1) if(pos[1] >= i && s[i] == '*') pre = i;
		if(a[n] - a[pos[1]] > a[pos[1]]) printf("%d %d\n", a[n] - a[pos[1]], lst - pos[1]);
		else if(a[n] - a[pos[1]] < a[pos[1]]) printf("%d %d\n", a[pos[1]], pos[1] - pre);
		else printf("%d %d\n", a[pos[1]], min(lst - pos[1], pos[1] - pre));
		return 0;
	}
	printf("%d ", a[n]);
	int l = 1, r = n, res = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid - 1, res = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << res << endl;
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