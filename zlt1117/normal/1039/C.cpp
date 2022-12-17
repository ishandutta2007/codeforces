#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#pragma GCC ("fast") 
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int> 
#define ll long long
#define iter set<int>::iterator
#define sz(x) (int)(x.size())
#define pb push_back
using namespace std;
const int maxn=1e6+5,maxm=1e6+5,mod=1e9+7;
struct edge
{
	int u,v;
}e[maxn];
int fa[maxn],n,m,L,tot;//,siz[maxn];
ll val[maxn],pw2[maxn],temp[maxn];
vector<int>v[maxn]; 
ll ans;
bool vis[maxn];
inline int get(int x)
{
	if(x==fa[x])return x;
	else return fa[x]=get(fa[x]); 
}
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return (f==1)?x:-x;
}
inline ll gll()
{
	ll x=0;int f=1;
	char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return (f==1)?x:-x;
}
inline ll qpow(ll x,ll k)
{
	ll ret=1;
	while(k)
	{
		if(k&1)ret=(ret*x)%mod;
		k>>=1,x=(x*x)%mod;
	}
	return ret;
}
int main()
{
//	freopen("virus.in","r",stdin);
//	freopen("virus.out","w",stdout);
	double st=clock();
	n=gi(),m=gi(),L=gi();
	FOR(i,1,n)val[i]=gll(),fa[i]=i;//siz[i]=1;
	FOR(i,1,m)e[i].u=gi(),e[i].v=gi();
	pw2[0]=1,pw2[1]=2;
	FOR(i,2,max(L,n))pw2[i]=pw2[i-1]*2%mod;///n
	FOR(i,1,m)
	{
		ll value=val[e[i].u]^val[e[i].v];
		temp[i]=value;
	}
	sort(temp+1,temp+m+1);
	tot=unique(temp+1,temp+m+1)-temp-1;
	FOR(i,1,m)
	{
		ll value=val[e[i].u]^val[e[i].v];
		int pos=lower_bound(temp+1,temp+tot+1,value)-temp;
		v[pos].push_back(i); 
	}
	FOR(i,1,tot)
	{
		vector<int>vec;vec.clear();
		FOR(j,0,sz(v[i])-1)
		{
			int id=v[i][j];
			int fu=get(e[id].u);
			int fv=get(e[id].v);
			vec.pb(e[id].u);
			vec.pb(e[id].v);
			if(fu!=fv)fa[fu]=fv;//,siz[fv]+=fu;
		}
		ll sum=1;
		int cnt=0;
		FOR(j,0,sz(vec)-1)if(get(vec[j])==vec[j]&&!vis[vec[j]])vis[vec[j]]=1,cnt++;
		sum=pw2[cnt];
		FOR(j,0,sz(vec)-1)if(get(vec[j])==vec[j])vis[vec[j]]=0;
		cnt=0;
		FOR(j,0,sz(vec)-1)if(!vis[vec[j]])cnt++,vis[vec[j]]=1;
		sum=sum*pw2[n-cnt]%mod;
		ans+=((pw2[n]-sum)%mod+mod)%mod;
		ans=ans%mod;
		FOR(j,0,sz(vec)-1)fa[vec[j]]=vec[j],vis[vec[j]]=0;//,siz[vec[j]]=1;
	}
	ll div=pw2[n]*pw2[L]%mod;
	ans=(div-ans+mod)%mod;
	ans=(ans+mod)%mod;
	printf("%lld\n",ans);
	return 0;
} ///