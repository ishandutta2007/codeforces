#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<assert.h>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=55;
const int maxk=6;
const int maxm=2500;
const int inf=1e9;
int n,k;
int dlim[maxk];
struct edge{int from,to,val;}e1[15],e2[maxm];int cnt1,cnt2;
int ans;
int d[maxk];
bool ini[maxm],x[maxm],y[maxm];int dis[maxm],pre[maxm];
struct dsu
{
	int fa[maxn];
	void prework(){for(int i=1;i<=n;i++)fa[i]=i;}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y){fa[get(x)]=get(y);}
	bool check(int x,int y){return get(x)==get(y);}
}S;
queue<int>q;bool inq[maxm];
int ret=0;
bool deb=0;
struct graph
{
	int head[maxm],ver[maxm*maxm],nxt[maxm*maxm],val[maxm*maxm],tot;
	void add(int x,int y,int z){ver[++tot]=y;val[tot]=z;nxt[tot]=head[x];head[x]=tot;}
	void clear(){tot=0;for(int i=1;i<=cnt2+2;i++)head[i]=0;}
	int dis[maxm],pre[maxm],len[maxm];bool inq[maxm];
	void spfa()
	{
		for(int i=1;i<=cnt2+2;i++)dis[i]=0x3f3f3f3f,inq[i]=0,pre[i]=0;
		dis[cnt2+1]=0;q.push(cnt2+1);inq[cnt2+1]=1;
		while(!q.empty())
		{
			int now=q.front();q.pop();inq[now]=0;
			for(int i=head[now];i;i=nxt[i])
				if(dis[ver[i]]>dis[now]+val[i]||(dis[ver[i]]==dis[now]+val[i]&&len[ver[i]]>len[now]+1))
				{dis[ver[i]]=dis[now]+val[i];len[ver[i]]=len[now]+1;pre[ver[i]]=now;if(!inq[ver[i]])q.push(ver[i]);inq[ver[i]]=1;}
		}
	}
	void update()
	{
		int now=cnt2+2;
		while(now){ini[now]^=1;if(ini[now])ret-=e2[now].val;else ret+=e2[now].val;now=pre[now];}
	}
}o;
bool calc(int chose)
{
	for(int i=1;i<=k;i++)d[i]=0;S.prework();
	for(int i=1;i<=cnt1;i++)if((chose>>(i-1))&1){d[e1[i].from]++,d[e1[i].to]++;S.merge(e1[i].from,e1[i].to);}
	for(int i=1;i<=cnt2;i++)if(ini[i]){if(e2[i].from<=k)d[e2[i].from]++;S.merge(e2[i].from,e2[i].to);}
	int s=cnt2+1,t=cnt2+2;o.clear();
	
	for(int i=1;i<=cnt2;i++)
	{
		if(ini[i])x[i]=y[i]=0;
		else
		{
			x[i]=(!S.check(e2[i].from,e2[i].to));
			y[i]=(e2[i].from>k||d[e2[i].from]+1<=dlim[e2[i].from]);
			if(x[i])o.add(s,i,e2[i].val);
			if(y[i])o.add(i,t,0);
		}
	}
	for(int i=1;i<=cnt2;i++)
	{
		if(!ini[i])continue;
		S.prework();
		for(int j=1;j<=cnt2;j++)if(ini[j]&&j!=i)S.merge(e2[j].from,e2[j].to);
		for(int i=1;i<=cnt1;i++)if((chose>>(i-1))&1)S.merge(e1[i].from,e1[i].to);
		for(int j=1;j<=cnt2;j++)
		{
			if(ini[j])continue;
			if(!S.check(e2[j].from,e2[j].to))o.add(i,j,e2[j].val);
			if(e2[j].from>k||d[e2[j].from]-(e2[j].from==e2[i].from)<dlim[e2[j].from])o.add(j,i,-e2[i].val);
		}
	}
	o.spfa();
	assert(o.dis[t]>=0);
	if(o.dis[t]==0x3f3f3f3f)return false;
	o.update();
	return true;
}
void solve(int chose)
{
	for(int i=1;i<=k;i++)d[i]=0;
	S.prework();
	ret=0;
	for(int i=1;i<=cnt1;i++)
		if((chose>>(i-1))&1)
		{
			d[e1[i].from]++;d[e1[i].to]++;ret+=e1[i].val;
			if(d[e1[i].from]>dlim[e1[i].from])return;if(d[e1[i].to]>dlim[e1[i].to])return;
			if(S.check(e1[i].from,e1[i].to))return;
			S.merge(e1[i].from,e1[i].to);
		}
	for(int i=1;i<=cnt2;i++)ini[i]=0;
	int cnt=0;
	if(ret>ans)return;
	while(calc(chose))if(ret>ans)return;
	ret=0;
	S.prework();
	for(int i=1;i<=cnt1;i++)if((chose>>(i-1))&1)S.merge(e1[i].from,e1[i].to),ret+=e1[i].val;
	for(int i=1;i<=cnt2;i++)if(ini[i])S.merge(e2[i].from,e2[i].to),ret+=e2[i].val;
	for(int i=1;i<=n;i++)if(!S.check(1,i))return;
	ans=min(ret,ans);
}
int main()
{
	n=read();k=read();
	for(int i=1;i<=k;i++)dlim[i]=read();
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=n-i;j++)
			if(i<=k&&i+j<=k){cnt1++;e1[cnt1].from=i;e1[cnt1].to=i+j;e1[cnt1].val=read();}
			else{cnt2++;e2[cnt2].from=i;e2[cnt2].to=i+j;e2[cnt2].val=read();}
	ans=inf;
	for(int i=0;i<(1<<cnt1);i++)solve(i);
	printf("%d\n",ans);
	return 0;
}