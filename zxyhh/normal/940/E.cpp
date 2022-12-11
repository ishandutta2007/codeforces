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
#define maxn 100005
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
int n,k;
ll a[maxn],f[maxn],sum[maxn],st[maxn][20];
struct zxy
{
	int l,r,ls,rs,Min;
}tr[maxn<<2];
int cnt;
void build(int l,int r)
{
    int pos=++cnt;
    tr[pos].l=l;tr[pos].r=r;tr[pos].ls=tr[pos].rs=-1;
    if (l==r) { tr[pos].Min=l; return; }
    int mid=l+r>>1;
    tr[pos].ls=cnt+1;build(l,mid);tr[pos].rs=cnt+1;build(mid+1,r);
    tr[pos].Min=f[tr[tr[pos].ls].Min]<f[tr[tr[pos].rs].Min]?tr[tr[pos].ls].Min:tr[tr[pos].rs].Min;
}
int findmin(int pos,int l,int r)
{
    if (l==tr[pos].l&&r==tr[pos].r) return tr[pos].Min;
    int ls=tr[pos].ls,rs=tr[pos].rs;
    int mid=tr[pos].l+tr[pos].r>>1;
    if (r<=mid) return findmin(ls,l,r);
    else if (l>mid) return findmin(rs,l,r);
    else { int x1=findmin(ls,l,mid),x2=findmin(rs,mid+1,r);
    return f[x1]<f[x2]?x1:x2;
    }
}
inline int qmin(int l,int r)
{
    int ln=log(r-l+1)/log(2);
    return min(st[l][ln],st[r-(1<<ln)+1][ln]);
}
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    n=rd(),k=rd();
    rep(i,1,n) a[i]=rd();
    rep(i,1,n) sum[i]=sum[i-1]+a[i],st[i][0]=a[i];
    rep(j,1,20)
    rep(i,1,n-(1<<j)+1)
    st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    //build(0,n);
    rep(i,1,n)
        if (i>=k) f[i]=min(f[i-1]+a[i],f[i-k]+sum[i]-sum[i-k]-qmin(i-k+1,i));
        else f[i]=f[i-1]+a[i];
    //rep(i,1,n) wrt(f[i],' ');
    //PC('\n');
    wrt(f[n],'\n');
    flush();
    return 0;
}