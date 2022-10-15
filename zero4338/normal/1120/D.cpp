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
const int maxn=1e6+5,mod=998244353;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,c[maxn],lim;
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	ll f[maxn],g[maxn];int fcnt[maxn],gcnt[maxn];
	vector<int>ffr[maxn];int gtyp[maxn];// 0 only sumg , 1 both , 2 only f+c
	bool visf[maxn],visg[maxn];
	void dfs(int u,int fa)
	{
		if(e[u].size()==1&&u!=1){f[u]=0;g[u]=c[u];fcnt[u]=gcnt[u]=1;gtyp[u]=1;return;}
		int mulgcnt=1;
		for(int &i:e[u])
		{
			if(i==fa)continue;
			dfs(i,u);
			mulgcnt=(ll)mulgcnt*gcnt[i]%mod;
			g[u]+=g[i];
			if(!ffr[u].empty()&&g[ffr[u][0]]-f[ffr[u][0]]<g[i]-f[i])ffr[u].clear();
			if(ffr[u].empty()||g[ffr[u][0]]-f[ffr[u][0]]==g[i]-f[i])ffr[u].push_back(i);
		}
		f[u]=g[u];f[u]-=g[ffr[u][0]]-f[ffr[u][0]];		
		for(int &i:ffr[u])
			(fcnt[u]+=(ll)fcnt[i]*qpow(gcnt[i],mod-2)%mod)%=mod;
		fcnt[u]=(ll)fcnt[u]*mulgcnt%mod;
		if(g[u]<f[u]+c[u])
		{
			gtyp[u]=0;
			gcnt[u]=mulgcnt;
		}
		else if(g[u]==f[u]+c[u])
		{
			gtyp[u]=1;
			gcnt[u]=(mulgcnt+fcnt[u])%mod;
		}
		else if(g[u]>f[u]+c[u])
		{
			gtyp[u]=2;
			g[u]=f[u]+c[u];
			gcnt[u]=fcnt[u];
		}
	}
	void spread(int u,int fa)
	{
		if(e[u].size()==1&&u!=1)return;
		if(visg[u])
		{
			if(gtyp[u]<=1)
			{
				for(int &i:e[u])
					if(i!=fa)visg[i]=1;
			}
			if(gtyp[u]>=1)visf[u]=1;
		}
		if(visf[u])
		{
			if(ffr[u].size()==1)
			{
				for(int &i:e[u])
					if(i!=fa&&i!=ffr[u][0])visg[i]=1;
			}
			else
			{
				for(int &i:e[u])
					if(i!=fa)visg[i]=1;
			}
			for(int &i:ffr[u])visf[i]=1;
		}
		for(int &i:e[u])if(i!=fa)spread(i,u);
	}
}o;
int main()
{
	n=read();
	generate_n(c+1,n,read);
	for(int i=1;i<n;i++)o.add(read(),read());
	o.dfs(1,0);o.visg[1]=1;o.spread(1,0);
	int cnt=0;
	for(int i=1;i<=n;i++)if(o.visg[i]&&o.gtyp[i]>=1)cnt++;
	printf("%lld %d\n",o.g[1],cnt);
	for(int i=1;i<=n;i++)if(o.visg[i]&&o.gtyp[i]>=1)printf("%d ",i);putchar('\n');
	return 0;
}