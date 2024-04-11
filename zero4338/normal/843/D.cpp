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
const int maxn=1e5+5;
int n,m,q;
class graph
{
	public:
	struct edge{int to,v,nxt;}e[maxn];int tot,head[maxn];
	int dep[maxn];
	void add(int x,int y,int z){e[++tot]={y,z,head[x]};head[x]=tot;}
	ll dis[maxn];
	bool vis[maxn];
	void dfs(int u)
	{
		vis[u]=true;
		for(int i=head[u];i;i=e[i].nxt)
			if(!vis[e[i].to])
			{
				dep[e[i].to]=dep[u]+1;
				dis[e[i].to]=dis[u]+e[i].v;
				dfs(e[i].to);
			}
	}
	void init()
	{
		struct node{int x;ll d;bool operator >(const node &rhs)const{return d>rhs.d;}};
		memset(dis,0x3f,sizeof dis);
		priority_queue<node,vector<node>,greater<node>>q;
		q.push({1,0});dis[1]=0;
		while(!q.empty())
		{
			auto now=q.top();q.pop();
			if(now.d>dis[now.x])continue;
			for(int i=head[now.x];i;i=e[i].nxt)
				if(dis[e[i].to]>now.d+e[i].v)
				{
					dis[e[i].to]=now.d+e[i].v;
					q.push({e[i].to,dis[e[i].to]});
				}
		}
	}
	void add(const vector<int>&id)
	{
		static ll del[maxn];
		static vector<int>buc[maxn];
		memset(del,0x3f,sizeof del);
		del[1]=0;buc[0].push_back(1);
		for(auto &i:id)e[i].v++;
		for(int i=0;i<=n-1;i++)
		{
			for(int it=0;it<buc[i].size();it++)
			{
				int j=buc[i][it];
				if(del[j]<i)continue;
				for(int k=head[j];k;k=e[k].nxt)
				{
					ll v=dis[j]+e[k].v-dis[e[k].to];
					if(del[e[k].to]>del[j]+v)
					{
						del[e[k].to]=del[j]+v;
						if(del[e[k].to]<n)
							buc[del[e[k].to]].push_back(e[k].to);
					}
				}
			}
			buc[i].clear();
		}
		for(int i=1;i<=n;i++)
			if(vis[i])dis[i]+=del[i];
	}
	ll query(int u)
	{
		if(!vis[u])return -1;
		return dis[u];
	}
}o;
int main()
{
	n=read();m=read();q=read();
	for(int i=1;i<=m;i++){int u=read(),v=read(),c=read();o.add(u,v,c);}
	o.dfs(1);o.init();
	while(q--)
	{
		int opt=read();
		if(opt==1)printf("%lld\n",o.query(read()));
		else
		{
			vector<int>e(read());
			generate(e.begin(),e.end(),read);
			o.add(e);
		}
	}
	return 0;
}