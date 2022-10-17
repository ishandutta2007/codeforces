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
const int P = 1000000007;
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int ksm(int a, int b, int P) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
 
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
struct Node {
	int x, y;
	bool operator < (const Node b) const {return x < b.x;}
}a[MAXN];

signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    int n; FI(n);
    For(i, 1, n) FI(a[i].x); For(i, 1, n) FI(a[i].y);
	sort(a + 1, a + 1 + n); 
	int res = 0;
	for(int i = 1; i <= n; ) {
		priority_queue < int > q;
		int sum = a[i].y, cur = a[i].x, j = i + 1; q.push(a[i].y);
		while(1) {
			while(j <= n && a[j].x == cur) {
				q.push(a[j].y), sum += a[j++].y;
			}
			if(q.size() == 1) break;
			res += (sum -= q.top()); q.pop(); cur++;
		}
//		cerr << i << ' ' << j << endl;;
		i = j;
	}
	cout << res << endl;
    return FastIO::Fflush(), 0;
}
/*
4
ngww
1 2
2 3
3 4
1
3 4 4 3
*/