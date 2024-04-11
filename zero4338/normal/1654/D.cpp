#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=2e5+5,mod=998244353;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n;
int mp[maxn],p[maxn],cnt,inv[maxn];
void prework()
{
	n=2e5;
	inv[1]=1;for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	mp[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!mp[i]){p[++cnt]=i;mp[i]=i;}
		for(int j=1;j<=cnt&&p[j]*i<=n;j++)
		{
			mp[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
}
int ans;
int now[maxn],his[maxn],val;
void add(int x)
{
	while(x!=1)
	{
		now[mp[x]]++;
		his[mp[x]]=max(his[mp[x]],now[mp[x]]);
		x/=mp[x];
	}
}
void del(int x)
{
	while(x!=1)
	{
		now[mp[x]]--;
		x/=mp[x];
	}
}
struct graph
{
	vector<tuple<int,int,int>>e[maxn];
	void clear(){for(int i=1;i<=n;i++)e[i].clear();}
	void add(int x,int y,int a,int b)
	{
		e[x].push_back({y,a,b});// x/y== a/b
		e[y].push_back({x,b,a});
	}
	void dfs0(int u,int fa)
	{
		for(auto &i:e[u])
		{
			if(get<0>(i)==fa)continue;
			del(get<2>(i));
			::add(get<1>(i));
			dfs0(get<0>(i),u);
			del(get<1>(i));
			::add(get<2>(i));
		}
	}
	void dfs1(int u,int fa)
	{
		(ans+=val)%=mod;
		for(auto &i:e[u])
		{
			if(get<0>(i)==fa)continue;
			val=(ll)val*inv[get<1>(i)]%mod;
			val=(ll)val*get<2>(i)%mod;
			dfs1(get<0>(i),u);
			val=(ll)val*get<1>(i)%mod;
			val=(ll)val*inv[get<2>(i)]%mod;	
		}
	}
}o;
int main()
{
	prework();
	T=read();
	while(T--)
	{
		n=read();o.clear();
		for(int i=1;i<n;i++)
		{
			int x=read(),y=read(),a=read(),b=read();
			o.add(x,y,a,b);
		}
		memset(now,0,sizeof(int)*(n+1));
		memset(his,0,sizeof(int)*(n+1));
		ans=0;
		o.dfs0(1,0);
		val=1;
		for(int i=1;i<=n;i++)if(his[i])val=(ll)val*qpow(i,his[i])%mod;
		o.dfs1(1,0);
		printf("%d\n",ans);
	}
	return 0;
}