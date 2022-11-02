#include<bits/stdc++.h>
using namespace std;
namespace zld3794955 {
const int N=200020,M=200020,D=20,bar=19;
const int mod=998244353;
struct info
{
	int s,d,dir;
};
int n,m,last[N]={},next[M+M]={},dir[M+M]={},end[M+M]={},total_edge=0;
pair<int,int> dis[N][D][2];
queue<info> q;
bool in[N][D][2]={};
void add_edge(int u,int v,int d)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	dir[total_edge]=d;
	end[total_edge]=v;
}
void work()
{
	for(int i=1;i<=n;++i)
		for(int j=0;j<=bar;++j)
			dis[i][j][0]=dis[i][j][1]=make_pair(mod,mod);
	q.push((info){1,0,0});
	dis[1][0][0]=make_pair(0,0);
	in[1][0][0]=true;
	while(!q.empty())
	{
		info now=q.front();
		q.pop();
		in[now.s][min(now.d,bar)][now.dir]=false;
		//cout<<now.s<<' '<<now.d<<' '<<now.dir<<endl;
		pair<int,int> nowdis=dis[now.s][min(now.d,bar)][now.dir];
		//cout<<nowdis.first<<' '<<nowdis.second<<endl;
		//system("pause");
		for(int i=last[now.s];i;i=next[i])
		{
			int j=end[i];
			pair<int,int> todis=make_pair(nowdis.first+(now.dir!=dir[i]),nowdis.second+1);
			int d=todis.first;
			if(todis<dis[j][min(d,bar)][dir[i]])
			{
				dis[j][min(d,bar)][dir[i]]=todis;
				if(!in[j][min(d,bar)][dir[i]])
				{
					in[j][min(d,bar)][dir[i]]=true;
					q.push((info){j,d,dir[i]});
				}
			}
		}
	}
	int ans=mod;
	for(int i=0;i<bar;++i)
		for(int dir=0;dir<=1;++dir)
			if(dis[n][i][dir].first==i)
			{
				int tmp=1;
				for(int j=1;j<=i;++j)
					tmp=tmp*2;
				--tmp;
				tmp=tmp+dis[n][i][dir].second;
				ans=min(ans,tmp);
			}
	if(ans<mod)
	{
		printf("%d\n",ans);
		return;
	}
	int tmp=1,d=(dis[n][bar][0]>dis[n][bar][1]);
	for(int i=1;i<=dis[n][bar][d].first;++i)
		tmp=tmp*2%mod;
	tmp=(tmp+dis[n][bar][d].second-1+mod)%mod;
	printf("%d\n",tmp);
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v,0);
		add_edge(v,u,1);
	}
	work();
}
}
int main()
{
	zld3794955::init();
}