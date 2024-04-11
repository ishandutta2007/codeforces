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
#define rep(x,a,b) for (register int x=int(a);x<=(int)(b);x++)
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
#define mod 1000000007
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
int n,pris;
int dp[80][(1<<19)+5],S[100];
int rk[100];
struct zxy
{
	int s[30],sum,num[30];
}a[100];
bool vis[1000];
int pri[1000>>2],tp,Min[1000];
int f1[100],f0[100];
inline void OL(int k)
{
    vis[1]=1;
	rep(i,2,k){
		if (!vis[i]) pri[++tp]=i,Min[i]=i;
		for(int j=1;j<=tp&&pri[j]*i<=k;j++){
			vis[pri[j]*i]=1,Min[pri[j]*i]=pri[j];
			if (i%pri[j]==0) break;
		}
	}
}
inline void  fj(zxy &x,int k)
{
	while (k>1) {
		x.sum++;x.num[x.sum]=Min[k];
		while (Min[k]==x.num[x.sum]) x.s[x.sum]++,k/=Min[k];
	}
}
inline int power(int x,int k)
{
	ll x1=x,ans=1;
	for(;k;k=k>>1,x1*=x1,x1%=mod) if (k&1) ans=(ans*x1)%mod;
	return ans;
}
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	n=rd();
	OL(100);rep(i,1,70) fj(a[i],i);
	rep(i,1,tp) rk[pri[i]]=pris++;
	rep(i,1,n) S[rd()]++;
	rep(i,1,100) if (S[i]>0) f0[i]=power(2,S[i]-1),f1[i]=f0[i];
	else f0[i]=1;
	dp[0][0]=1;
	rep(i,1,70){
	    if (S[i]>0){
		    rep(j,0,(1<<19)-1){
			    int p=j;
			    rep(k,1,a[i].sum) p^=(a[i].s[k]&1)<<rk[a[i].num[k]];
			    dp[i][p]=(1ll*dp[i][p]+1ll*dp[i-1][j]*f1[i])%mod;
	 	    }
	    }
	    rep(j,0,(1<<19)-1) dp[i][j]=(1ll*dp[i][j]+1ll*dp[i-1][j]*f0[i])%mod;
	}
	wrt(dp[70][0]-1,'\n');flush();
}