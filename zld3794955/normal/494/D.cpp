#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010,D=20,mod=1000000007;
int n,last[N]={},next[N+N]={},end[N+N]={},l[N+N]={},total_edge=0;
int f[N][D]={},d[N]={};
long long size[N]={},s[N][4]={},g[N][D]={};
inline void add_edge(int u,int v,int len)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	l[total_edge]=len;
}
void init()
{
	scanf("%d",&n);
	for(int i=1,u=0,v=0,l=0;i<n;++i)
	{
		scanf("%d%d%d",&u,&v,&l);
		add_edge(u,v,l);
		add_edge(v,u,l);
	}
}
void dfs1(int p)
{
	size[p]=1ll;
	for(int i=last[p];i;i=next[i])
	{
		int j=end[i];
		if(end[i]==f[p][0])
			continue;
		f[j][0]=p;
		g[j][0]=l[i];
		d[j]=d[p]+1;
		dfs1(j);
		size[p]+=size[j];
		(s[p][0]+=size[j]*l[i]+s[j][0])%=mod;
		(s[p][1]+=s[j][1]+size[j]*l[i]%mod*l[i]+2*l[i]*s[j][0])%=mod;
	}
}
void dfs2(int p)
{
	for(int i=last[p];i;i=next[i])
	{
		int j=end[i];
		if(j==f[p][0])
			continue;
		s[j][2]=s[p][2]+s[p][0]-(size[j]*l[i]+s[j][0])+l[i]*(n-size[j]);
		s[j][2]=(s[j][2]%mod+mod)%mod;
		long long tmp=(s[p][2]+s[p][0]-size[j]*l[i]-s[j][0])%mod+mod;
		s[j][3]=s[p][3]+s[p][1]-s[j][1]-size[j]*l[i]%mod*l[i]-2*l[i]*s[j][0];
		s[j][3]+=(n-size[j])*l[i]%mod*l[i]+2*l[i]*tmp;
		s[j][3]=(s[j][3]%mod+mod)%mod;
		dfs2(j);
	}
}
void dp()
{
	dfs1(1);
	dfs2(1);
	//for(int i=1;i<=n;++i)
	//	cout<<s[i][0]<<' '<<s[i][1]<<' '<<s[i][2]<<' '<<s[i][3]<<endl;
	for(int d=1,s=2;s<=n;s*=2,++d)
		for(int i=1;i<=n;++i)
		{
			f[i][d]=f[f[i][d-1]][d-1];
			g[i][d]=g[i][d-1]+g[f[i][d-1]][d-1];
		}
}
int calc(int u,int v)
{
	//cout<<"u="<<u<<" v="<<v<<endl;
	static const int maxd=17;
	int u_=u,v_=v;
	long long sl=0;
	if(d[u]<d[v])
		swap(u,v);
	for(int i=maxd;i>=0;--i)
		if(d[u]-(1<<i)>=d[v])
			sl+=g[u][i],u=f[u][i];
	if(u!=v)
	{
		for(int i=maxd;i>=0;--i)
			if(f[u][i]!=f[v][i])
			{
				sl+=g[u][i]+g[v][i];
				u=f[u][i];
				v=f[v][i];
			}
		sl+=g[u][0]+g[v][0];
		u=f[u][0],v=f[v][0];
	}
	sl%=mod;
	//cout<<"sl="<<sl<<" LCA="<<u<<endl;
	if(u==v_)
	{
		//cout<<"case2"<<endl;
		u=u_,v=v_;
		long long tmp1=s[u][1]+s[u][3];
		long long tmp2=s[v][3]+2*s[v][2]*sl+(n-size[v])*sl%mod*sl;
		//cout<<"tmp1="<<tmp1<<" tmp2="<<tmp2<<endl;
		return ((tmp1-tmp2-tmp2)%mod+mod)%mod;
	}
	else
	{
		//cout<<"case1"<<endl;
		u=u_,v=v_;
		long long tmp1=s[u][1]+s[u][3];
		long long tmp2=s[v][1]+2*s[v][0]*sl+size[v]*sl%mod*sl;
		//cout<<"tmp1="<<tmp1<<" tmp2="<<tmp2<<endl;
		return ((tmp2+tmp2-tmp1)%mod+mod)%mod;
	}
}
void query()
{
	int q,u,v;
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d",&u,&v);
		printf("%d\n",calc(u,v));
	}
}
int main()
{	
	init();
	dp();
	query();
	return 0;
}