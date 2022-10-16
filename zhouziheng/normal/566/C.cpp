#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

struct e
{
	int to;double val;
	e(int t=0,double v=0):to(t),val(v){}
};vector<e> ed[400000];

double w[400000];
int sz[400000],maxsz[400000];double dis[400000];
bool ban[400000];
vector<int> all_nd;
void dfs_bas(int u,int f)
{
	all_nd.push_back(u);
	sz[u]=1,maxsz[u]=0;int maxv=0;
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;if(v==f||ban[v])continue;
		dfs_bas(v,u);
		sz[u]+=sz[v];maxsz[u]=max(maxsz[u],sz[v]);
	}
}

double der[400000];
double dfs_calc(int u,int f)
{
	der[u]=w[u]*1.5*pow(dis[u],0.5);double sum=w[u]*pow(dis[u],1.5);
	for(int i=0;i<ed[u].size();i++)
	{
		int v=ed[u][i].to;if(v==f)continue;
		dis[v]=dis[u]+ed[u][i].val;sum+=dfs_calc(v,u);der[u]+=der[v];
	}
	return sum;
}
double ans;int pos;
void work(int u)
{
	int rt=0;all_nd.clear();dfs_bas(u,0);
	for(int i=0;i<all_nd.size();i++){maxsz[all_nd[i]]=max(maxsz[all_nd[i]],sz[u]-sz[all_nd[i]]);}
	rt=all_nd[0];for(int i=1;i<all_nd.size();i++)if(maxsz[all_nd[i]]<maxsz[rt])rt=all_nd[i]; 
	if(!rt)return;dis[rt]=0;double sum=dfs_calc(rt,0);
	if(ans>sum){ans=sum,pos=rt;}
	ban[rt]=1;double sumd=der[rt];
	//printf("%d %d\n",u,rt);
	for(int i=0;i<ed[rt].size();i++)
	{
		int v=ed[rt][i].to;if(!ban[v]&&sumd-2*der[v]<=0){work(v);break;}
	}
}

int main()
{
	int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%lf",&w[i]);
	for(int i=1,x=0,y=0;i<n;i++)
	{
		double v=0;scanf("%d%d%lf",&x,&y,&v);ed[x].push_back(e(y,v)),ed[y].push_back(e(x,v));
	}
	ans=1e20;work(1);printf("%d %.10lf",pos,ans);return 0;
}