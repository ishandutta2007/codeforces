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
	    ll x=0;int ch=Getchar(); bool f=1;
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
int n,a[maxn],m,k;
struct zxy
{
	ll x,y,z;
}b[maxn];
int X[maxn],Y[maxn];
ll sum[maxn],ans[maxn];
inline void init()
{
	n=rd();m=rd(),k=rd();
	rep(i,1,n) a[i]=rd();
	rep(i,1,m) b[i].x=rd(),b[i].y=rd(),b[i].z=rd();
	rep(i,1,k) X[i]=rd(),Y[i]=rd();
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	init();
	rep(i,1,k) sum[X[i]]++,sum[Y[i]+1]--;
	rep(i,1,m) ans[i]=ans[i-1]+sum[i],b[i].z*=ans[i];
	memset(sum,0,sizeof(sum));memset(ans,0,sizeof(ans));
	rep(i,1,m) 
	sum[b[i].x]+=b[i].z,sum[b[i].y+1]-=b[i].z;
	rep(i,1,n) ans[i]=ans[i-1]+sum[i],wrt(ans[i]+1ll*a[i],' ');
	PC('\n');
	flush();return 0;
 }