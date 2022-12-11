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
inline ll qpower(int k,ll x)
{
	if (k<0) return 0;
	ll ans=1;for(;k;k=k>>1,x=(x*x)%mod) if (k&1) ans=1ll*ans*x%mod;
	return ans;
}
int n;
int s[maxn],w[maxn];
ll ans,S1,S2,sum,sum1; 
inline void init(){
	n=rd();
	int ch=getchar();
	while ((!isdigit(ch))&&ch!='?') ch=GC();rep(i,1,n) s[i]=ch,ch=GC(),sum=ch=='?'?sum+1:sum;
	while ((!isdigit(ch))&&ch!='?') ch=GC();rep(i,1,n) w[i]=ch,ch=GC(),sum=ch=='?'?sum+1:sum;
}
inline ll big()
{
	ll re=1;
	rep(i,1,n) {
	    if (s[i]=='?'&&w[i]=='?') re*=55;
	    else if (s[i]=='?'&&w[i]!='?') re*='9'-w[i]+1;
	    else if (s[i]!='?'&&w[i]=='?') re*=s[i]-'0'+1;
	    re%=mod;
	}
	return re;
}
inline ll low()
{
	ll re=1;
	rep(i,1,n) { 
	    if (s[i]=='?'&&w[i]=='?') re*=55;
	    else if (s[i]=='?'&&w[i]!='?') re*=w[i]-'0'+1;
	    else if (s[i]!='?'&&w[i]=='?') re*='9'-s[i]+1;
	    re%=mod;
	}
	return re;
}

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
	init();
	sum=0;
	rep(i,1,n) { if (s[i]!='?'&&w[i]!='?'&&s[i]!=w[i]) if (s[i]>w[i])S1++;else S2++;
	    if (s[i]=='?') sum++;if (w[i]=='?') sum++;
	    if (s[i]=='?'&&w[i]=='?') sum1++;
	}
	ans=qpower(sum,10);
	if ((S1)&&(!S2)) ans-=big();
	else if ((!S1)&&(S2)) ans-=low();
	else if ((!S1)&&(!S2)) ans=(ans-(low()+big())+qpower(sum1,10))%mod;
	if (ans<0) ans+=mod;
	wrt(ans,'\n');
	flush();return 0; 
 }