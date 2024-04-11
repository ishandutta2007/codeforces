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
const int N = 3e5 + 5;

int n, m, c, x, col[N][2], fa[N << 1], sz[N << 1][2], ans;
char s[N];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
	ans -= min(sz[x][0], sz[x][1]) + min(sz[y][0], sz[y][1]);
	fa[y] = x;
	sz[x][0] += sz[y][0], sz[x][1] += sz[y][1];
	ans += min(sz[x][0], sz[x][1]);
}

int main(){
	scanf("%d%d%s", &n, &m, s + 1);
	++m;
	for(int i = 1; i < m; i++) {
		scanf("%d", &c);
		while(c--){
			scanf("%d", &x);
			col[x][(bool)col[x][0]] = i;
		}
	}
	for(int i = 0; i < (m << 1); i++) {
		fa[i] = i;
		sz[i][i >= m] = 1;
	}
	For(i, 1, n) {
		if(s[i] - '0'){
			merge(col[i][0], col[i][1]);
			merge(col[i][0] + m, col[i][1] + m);
		}else{
			merge(col[i][0], col[i][1] + m);
			merge(col[i][1], col[i][0] + m);
		}
		int x = find(0);
		if(sz[x][0] < sz[x][1]) printf("%d\n", (ans >> 1) - sz[x][0] + sz[x][1]);
		else printf("%d\n", ans >> 1);
	}
	return 0;
}