#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#define N 100100
using namespace std;

int n,m,bb,first[N],d[N],ans;
bool vis[N];
struct Bn
{
	int to,next,quan;
}bn[N<<1];
vector<int>vec;

inline void add(int u,int v,int w)
{
	bb++;
	bn[bb].to=v;
	bn[bb].quan=w;
	bn[bb].next=first[u];
	first[u]=bb;
}

inline void ad(int u)
{
	int i;
	for(i=0;i<vec.size();i++)
	{
		u=min(u,vec[i]^u);
	}
	if(u) vec.push_back(u);
}

void dfs(int now,int last)
{
	vis[now]=1;
	int p,q;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(abs(p-last)==1&&min(p,last)%2) continue;
		if(vis[bn[p].to]) ad(d[now]^d[bn[p].to]^bn[p].quan);
		else d[bn[p].to]=d[now]^bn[p].quan,dfs(bn[p].to,p);
	}
}

int main()
{
	memset(first,-1,sizeof(first));
	int i,j,p,q,o;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&p,&q,&o);
		add(p,q,o),add(q,p,o);
	}
	dfs(1,-1);
	ans=d[n];
	for(i=0;i<vec.size();i++)
	{
		ans=min(ans,ans^vec[i]);
	}
	cout<<ans;
}