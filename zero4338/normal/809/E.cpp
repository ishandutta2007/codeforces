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
const int maxn=2e5+5;
const int mod=1e9+7;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n;
int ans;
int phi[maxn],mu[maxn],inv[maxn];
void euler_sieve()
{
	static int p[maxn],cnt;
	static bool vis[maxn];
	phi[1]=1;mu[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])p[++cnt]=i,phi[i]=i-1,mu[i]=i-1;
		for(int j=1;j<=cnt&&p[j]*i<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j])phi[i*p[j]]=phi[i]*(p[j]-1),mu[i*p[j]]=mu[i]*(p[j]-1);
			else{phi[i*p[j]]=phi[i]*p[j];break;}
		}
	}
	inv[1]=1;for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
}
struct graph
{
	int val[maxn],p[maxn];
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int dep[maxn],dfn[maxn],eu[maxn<<1],tim;
	void dfs(int u,int fa)
	{
		dep[u]=dep[fa]+1;
		eu[dfn[u]=++tim]=u;
		for(int &i:e[u])
		{
			if(i==fa)continue;
			dfs(i,u);eu[++tim]=u;
		}
	}
	int mind(int &x,int &y){return dep[x]<dep[y]?x:y;}
	int st[21][maxn<<1];
	void prework()
	{
		for(int i=1;i<=tim;i++)st[0][i]=eu[i];
		for(int i=1;(1<<i)<=tim;i++)
			for(int j=1;j+(1<<i)-1<=tim;j++)st[i][j]=mind(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	int lca(int x,int y)
	{
		x=dfn[x];y=dfn[y];if(x>y)swap(x,y);
		int k=log2(y-x+1);return mind(st[k][x],st[k][y-(1<<k)+1]);
	}
}o;
struct vtree
{
	vector<int>e[maxn];
	int val[maxn],sum[maxn];
	void add(int x,int y){e[x].push_back(y);}
	int dfs(int u)
	{
		int ret=0;
		sum[u]=val[u];
		for(int &i:e[u])
		{
			(ret+=dfs(i))%=mod;
			(ret+=(ll)sum[u]*sum[i]%mod*4%mod*o.dep[u]%mod)%=mod;
			(sum[u]+=sum[i])%=mod;
		}
		e[u].clear();
		return ret;
	}
	int calc(int x)
	{
		int ret=0;
		static int p[maxn],cnt,sta[maxn],top;
		int allsum=0;
		cnt=0;for(int i=x;i<=n;i+=x)val[o.p[i]]=phi[i],p[++cnt]=o.p[i],(allsum+=phi[i])%=mod;
		sort(p+1,p+cnt+1,[](int &i,int &j){return o.dfn[i]<o.dfn[j];});
		for(int i=1;i<=cnt;i++)(ret+=2ll*o.dep[p[i]]%mod*phi[o.val[p[i]]]%mod*(allsum-phi[o.val[p[i]]]+mod)%mod)%=mod;	
		sta[top=1]=1;
		for(int i=1;i<=cnt;i++)
		{
			int now=p[i];
			if(now==1)continue;
			int fa=o.lca(sta[top],now);
			if(sta[top]!=fa)
			{
				while(o.dfn[sta[top-1]]>o.dfn[fa])add(sta[top-1],sta[top]),top--;
				if(sta[top-1]==fa)add(sta[top-1],sta[top]),top--;
				else add(fa,sta[top]),sta[top]=fa;
			}
			sta[++top]=now;
		}
		for(int i=1;i<=top-1;i++)add(sta[i],sta[i+1]);
		(ret+=mod-dfs(1))%=mod;
		for(int i=x;i<=n;i+=x)val[o.p[i]]=0;
		return ret;
	}
}v;
int main()
{
	n=read();
	generate_n(o.val+1,n,read);
	for(int i=1;i<=n-1;i++)o.add(read(),read());
	o.dfs(1,0);o.prework();euler_sieve();
	for(int i=1;i<=n;i++)o.p[o.val[i]]=i;
	for(int i=1;i<=n;i++)if(mu[i])ans=(ans+(ll)inv[mu[i]]*v.calc(i)%mod)%mod;
	ans=(ll)ans*qpow((ll)n*(n-1)%mod,mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}