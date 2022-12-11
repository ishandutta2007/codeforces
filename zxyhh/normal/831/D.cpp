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
#define maxn 1005
#define maxk 2005
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
int n,k,p;
ll a[maxn],b[maxk],dp[maxn][maxk],dp1[maxn][maxk];
inline ll Abs(ll x)
{
	return x<0?-x:x; 
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	n=rd(),k=rd(),p=rd();
	rep(i,1,n) a[i]=rd();
	rep(i,1,k) b[i]=rd();
	sort(b+1,b+1+k);sort(a+1,a+n+1);
	rep(i,1,n) rep(j,0,k) dp[i][j]=dp1[i][j]=1666666666666666;
	rep(i,1,n) rep(j,i,k) 
	dp[i][j]=max(dp1[i-1][j-1],Abs(a[i]-b[j])+Abs(b[j]-p)),dp1[i][j]=min(dp1[i][j-1],dp[i][j]);
	ll ans=1666666666666666;
	rep(i,1,k) ans=min(dp[n][i],ans);
	wrt(ans,'\n');
	flush();return 0; 
}