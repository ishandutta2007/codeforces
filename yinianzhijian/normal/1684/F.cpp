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
struct nod
{
	int l,r;
	bool operator<(const nod&w)const{return l==w.l?r>w.r:l<w.l;}
}e[xx];
void cl()
{
	sort(e+1,e+m+1);
	int mx=0,tt=0;
	for(int i=1;i<=m;i++)
	{
		if(mx<e[i].r)
			mx=e[i].r,e[++tt]=e[i];
	}
	m=tt;
}
int fr(int x)
{
	int l=1,r=m,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(e[mid].l<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	if(ans==0)return ans;
	return e[ans].r;
}
map<int,int>mp;
struct RR{int len1,len2,x1,y1,x2,y2;};
vector<RR>v;
int cf[xx];
void addd(int l,int r)
{
	l=max(l,1),r=min(r,n);
	if(l>r)return;
	cf[l]++,cf[r+1]--;
}
void re(){for(int i=1;i<=n;i++)cf[i]+=cf[i-1];}
void up(int a,int b,int c,int d)
{
	if(a==-1&&c==-1)return;
	if(a==-1)return addd(c,d);
	if(c==-1)return addd(a,b);
	if(a>c||((a==c)&&(b<d)))swap(a,c),swap(b,d);
	if(b>=d)return addd(a,b);
	if(b>=c)return addd(a,d);
	return addd(a,b),addd(c,d);
}
bool check(int mid)
{
	for(int i=1;i<=n;i++)cf[i]=0;
	for(auto it:v)
	{
		int q1l=-1,q1r=-1,q2l=-1,q2r=-1;
		if(mid>=it.len1)
		{
			q1l=max(1,it.y1+1-mid);
			q1r=it.x1;
			if(q1l>q1r)q1l=q1r=-1;
		}
		if(mid>=it.len2)
		{
			q2l=max(1,it.y2+1-mid);
			q2r=it.x2;
			if(q2l>q2r)q2l=q2r=-1;
		}
		up(q1l,q1r,q2l,q2r);
//		int x=it.x,y=it.y;
//		addd(x+1-mid,y);
	}
	re();
	for(int i=1;i<=n;i++)
//		if(cf[i]>=v.size())return cerr<<i<<"%%%\/n",1;
		if(cf[i]>=v.size())return 1;
	return 0;
}
map<int,vector<int> >Mp;
int main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=m;i++)
			e[i].l=read(),e[i].r=read();
		cl();
		sort(e+1,e+m+1);
		mp.clear();
		Mp.clear();
		v.clear();
		// 
		//vector 
		
		for(int i=1;i<=n;i++)Mp[a[i]].push_back(i);
//		for(int i=1;i<=n;i++)
//		{
//			if(mp[a[i]])
//			{
//				int l=mp[a[i]],r=fr(l);
//				if(r>=i)
//				v.push_back({mp[a[i]],i});
//			}
//			mp[a[i]]=i;
//		}
		int l=1,r=n,ans=0;
		for(auto it:Mp)
		{
			vector<int>&s=it.second;
			int tt=0;
			for(int j=0;j<s.size();j++)
			{
				tt=max(tt,j);
				int ty=fr(s[j]);
				while(tt+1<s.size()&&ty>=s[tt+1])tt++;
				if(tt==j)continue;
//				cout<<s[j]<<" "<<s[tt]<<"!!!!\n";
				// 
//				l=max(l,min(s[tt]-s[j+1]+1,s[tt-1]-s[j]+1));
//				l=max(l,s[tt-1]-s[j]+1);
//				v.push_back({s[tt-1],s[j+1]});
				v.push_back({s[tt-1]-s[j]+1,s[tt]-s[j+1]+1,s[j],s[tt-1],s[j+1],s[tt]});
			}
		}
		if(!v.size())
		{
			cout<<0<<"\n";
			continue;
		}
//		for(auto it:v)cout<<it.x<<" "<<it.y<<"%%\n";
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid))ans=mid,r=mid-1;
			else l=mid+1;
//			else r=mid-1;
		}
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}