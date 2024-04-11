#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define PC Putchar
#define GC Getchar
#define ll long long
#define ldb long double
#define pii pair<int,int>
#define pdd pair<double,double>
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
#define pb push_back
#define VI vector<int>
#define VS vector<string>
using namespace std;
namespace FAST_IO {
    #define IN_LEN 500000
    #define OUT_LEN 500000
    inline char Getchar() {
        static char buf[IN_LEN], *l=buf,*r=buf;
        if (l==r) r=(l=buf)+fread(buf,1,IN_LEN,stdin);
        return (l==r)?EOF:*l++;
    }
    char obuf[OUT_LEN], *ooh = obuf;
    inline void Putchar(char c) {
        if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout),ooh = obuf;
	    *ooh++ = c;
    }
    inline ll rd(){
	    ll x=0;int ch=GC(); bool f=1;
	    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=GC();
	    if (ch=='-'){f=0;ch=GC();}
        while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=GC();}
        return f?x:-x;
    }
    void write(ll x){ if (x>=10) write(x/10),PC((char)(x%10+'0')); else PC((char)(x+'0')); }
    inline void wrt(ll x,int p){if (x<0) PC('-'),x=-x; write(x); if (p) PC((char)p);}
    inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
}
using namespace FAST_IO;
#define maxn 1005
int n,m;
int a[maxn][maxn],b[maxn],ans[maxn][maxn],ans1[maxn][maxn];
inline int max(int A,int B) {return A>B?A:B;}
int main() {
    n=rd();m=rd();
    rep(i,1,n)
        rep(j,1,m)
            a[i][j]=rd();
    rep(i,1,n) {
        rep(j,1,m) b[j]=a[i][j];
        sort(b+1,b+1+m);
        int sz=unique(b+1,b+1+m)-b-1;
        rep(j,1,m) {
            ans[i][j]=max(ans[i][j],(lower_bound(b+1,b+1+sz,a[i][j])-b));
            ans1[i][j]=max(ans1[i][j],sz-(lower_bound(b+1,b+1+sz,a[i][j])-b));
        }
    }
    rep(j,1,m) {
        rep(i,1,n) b[i]=a[i][j];
        sort(b+1,b+1+n);
        int sz=unique(b+1,b+1+n)-b-1;
        rep(i,1,n) {
            ans[i][j]=max(ans[i][j],(lower_bound(b+1,b+1+sz,a[i][j])-b));
            ans1[i][j]=max(ans1[i][j],sz-(lower_bound(b+1,b+1+sz,a[i][j])-b));
        }
    }
    rep(i,1,n) {
        rep(j,1,m) wrt(ans[i][j]+ans1[i][j],' ');
        PC('\n');
    }
    flush();
}