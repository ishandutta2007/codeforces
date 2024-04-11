#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
	
int prim[xx],mn[xx],Cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}


int lb(int x){return x&-x;}
ll sum[xx];
void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}


}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
struct pr{int x,y;};
int n,m,k,q,a[xx],b[xx];
char s[xx];
map<int,int>mp,mp1;
struct nod{ll num,sum;}e[xx<<2];
//siz 
void build(int k,int l,int r)
{
	e[k]={0,0};
	if(l==r)return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
//y1 
void ins(int k,int l,int r,int x,int y)
{
	if(!x)return;
	e[k].num+=y,e[k].sum+=y*x;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)ins(k<<1,l,mid,x,y);
	else ins(k<<1|1,mid+1,r,x,y);
}
ll ef(int k,int l,int r,ll S)
{
	if(e[k].sum<=S)return e[k].num;
	if(l==r)
		return min(e[k].num,S/l);// 
	int mid=l+r>>1;
	if(e[k<<1].sum<=S)return e[k<<1].num+ef(k<<1|1,mid+1,r,S-e[k<<1].sum);
	return ef(k<<1,l,mid,S);
}
int main(){
	int T=read();
	while(T--)
	{
		mp.clear();
		mp1.clear();
		n=read(),k=read();
		ll ans=1e18;
		for(int i=1;i<=n;i++)a[i]=read();
		if(k>=n)
		{
			cout<<0<<"\n";
			continue;
		}
		build(1,1,n);
//		memset(e,0,sizeof(e[0])*(4*n));
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)mp[a[i]]=1,mp1[a[i]]++;
		int tt=mp.size();
		//-1 
		// 
		// 
		//diff>= 
		//=0 
		int ct=0;
		//=0 
		for(auto it:mp1)ins(1,1,n,it.second,1);
		for(int i=0;i<=n+1;i++)
		{
			if(i!=0)
			{
				//ct 
				ct+=(mp.find(i-1)==mp.end());
			}
			if(ct>k)continue;
			//diff+- 
			ll pans=tt+ct-i-ef(1,1,n,k);
//			cout<<i<<" "<<pans<<"%%\n";
			ans=min(ans,pans);
			ins(1,1,n,mp1[i],-1);
			//=i 
		}
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}