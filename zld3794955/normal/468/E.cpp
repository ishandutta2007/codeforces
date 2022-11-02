#include<bits/stdc++.h>
using namespace std;
const int N=100010,M=65,B=16,S=1<<B,P=M+M,K=P,mod=1000000007;
long long d[N]={1},sum[M][M]={},block=0,f1[2][S]={},f2[M][M][2]={};
int n,m,k,last[P]={},next[K]={},end[K]={},w[K]={},total_edge=1;
int part[P]={},q[2][P]={},t[2]={},bitcount[S]={};
bool v[P]={},in[K]={},dpv[P]={},DEBUG=true;
inline void add_edge(int u,int v,int l)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	w[total_edge]=l;
}
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		d[i]=d[i-1]*i%mod;
	for(int i=1;i<S;++i)
		bitcount[i]=bitcount[i-(i&(-i))]+1;
	map<int,int> num;
	for(int i=1,x,y,l;i<=m;++i)
	{
		cin>>x>>y>>l;
		x= (num[x]==0 ? num[x]=++k : num[x]);
		y= (num[y+n]==0 ? num[y+n]=++k : num[y+n]);
		part[x]=0, part[y]=1;
		(l+=mod-1)%=mod;
		add_edge(x,y,l);
		add_edge(y,x,l);
	}
}
void dfs1(int now)
{
	q[part[now]][++t[part[now]]]=now;
	v[now]=true;
	for(int i=last[now];i;i=next[i])
		if(!v[end[i]])
		{
			in[i]=in[i^1]=true;
			dfs1(end[i]);
		}
}
void dp1(int p)
{
	int ts=1<<t[p],num[P]={},pre=0,now=1;
	for(int i=1;i<=t[p];++i)
		num[q[p][i]]=i-1;
	f1[pre][0]=1ll;
	fill(f1[pre]+1,f1[pre]+ts,0ll);
	for(int s=1;s<=t[!p];++s)
	{
		for(int st=0;st<ts;++st)
		{
			f1[now][st]=f1[pre][st];
			for(int i=last[q[!p][s]];i;i=next[i])
				if(st&(1<<num[end[i]]))
					(f1[now][st]+=f1[pre][st^(1<<num[end[i]])]*w[i])%=mod;
		}
		swap(pre,now);
	}
	for(int state=0;state<ts;++state)
		(sum[block][bitcount[state]]+=f1[pre][state])%=mod;
}
int tree_dp(int s,int fa)
{
	int nowsize=0;
	long long tmp0[M]={},tmp1[M]={};
	for(int i=0;i<=m;++i)
		f2[s][i][0]=f2[s][i][1]=0ll;
	f2[s][0][0]=1ll;
	for(int i=last[s],p=end[i];i;i=next[i],p=end[i])
		if(in[i] && p!=fa)
		{
			int t=tree_dp(p,s);
			nowsize+=t;
			for(int k=0;k<=nowsize;++k)
			{
				tmp0[k]=f2[s][k][0],tmp1[k]=f2[s][k][1];
				f2[s][k][0]=f2[s][k][1]=0ll;
			}
			for(int k=nowsize;k>=0;--k)
				for(int j=0;j<=min(t,k);++j)
					(f2[s][k][0]+=tmp0[k-j]*f2[p][j][0])%=mod;
			if(!dpv[s])
			{
			for(int k=nowsize;k>=0;--k)
				for(int j=0;j<=min(t,k);++j)
					(f2[s][k][1]+=tmp1[k-j]*f2[p][j][0])%=mod;
			for(int k=nowsize;k>=0;--k)
				for(int j=0;j<=min(t,k);++j)
					(f2[s][k][1]+=tmp0[k-j]*w[i]%mod*f2[p][j][1])%=mod;}
		}
	if(!dpv[s])
	{
		for(int i=0;i<=nowsize;++i)
			tmp1[i]=f2[s][i][1];
		for(int i=0;i<=nowsize;++i)
			f2[s][i][1]=f2[s][i][0];
		if(tmp1[nowsize])
			++nowsize;
		for(int i=1;i<=nowsize;++i)
			(f2[s][i][0]+=tmp1[i-1])%=mod;
	}
	return nowsize;
}
void dp2()
{
	int u[K]={},v[K]={},l[K]={},tot=0,root=q[0][1];
	bool add[K]={};
	for(int s=1;s<=t[0];++s)
		for(int i=last[q[0][s]];i;i=next[i])
			if(!in[i] && !add[i])
			{
				add[i]=add[i^1]=true;
				u[tot]=q[0][s], v[tot]=end[i], l[tot]=w[i], ++tot;
			}
	for(int s=(1<<tot)-1;s>=0;--s)
	{
		fill(dpv+1,dpv+k+1,false);
		bool flag=true;
		long long tmp=1;
		for(int i=0;i<tot && flag;++i)
			if(s&(1<<i))
			{
				flag&=!dpv[u[i]] && !dpv[v[i]];
				dpv[u[i]]=dpv[v[i]]=true;
				(tmp*=l[i])%=mod;
			}
		if(!flag)
			continue;
		int size=tree_dp(root,0);
		for(int i=0;i<=size;++i)
			(sum[block][i+bitcount[s]]+=f2[root][i][0]*tmp)%=mod;
	}
}
void work()
{
	for(int i=1;i<=k;++i)
		if(!v[i])
		{
			t[0]=t[1]=0;
			++block;
			dfs1(i);
			if(t[0] && t[1])
				t[0]<=B ? dp1(0) : t[1]<=B ? dp1(1) : dp2();
		}
	long long f[M]={1ll},ans=0;
	for(int i=1;i<=block;++i)
		for(int k=m;k>=1;--k)
			for(int j=1;j<=min(m,k);++j)
				(f[k]+=f[k-j]*sum[i][j])%=mod;
	for(int i=0;i<=min(n,m);++i)
		(ans+=f[i]*d[n-i])%=mod;
	cout<<ans<<endl;
}
int main()
{
	init();
	work();
	return 0;
}