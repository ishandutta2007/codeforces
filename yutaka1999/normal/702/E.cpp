#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 300005
#define BT 512*1024*2
#define INF 1000000000000000LL

using namespace std;
typedef long long int ll;

struct segtree
{
	ll seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=INF;
	}
	void add(int k,ll x)
	{
		k+=mum-1;
		seg[k]=x;
		while(k>0)
		{
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return INF;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return min(vl,vr);
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
};
segtree seg;
vector <int> vec[SIZE];
int to[SIZE];
ll weight[SIZE];
int deg[SIZE];
bool cycle[SIZE];
ll sum[SIZE],mn[SIZE];
ll rt[SIZE],zan[SIZE];
int nd[SIZE];
int n;
ll K;

void dfs(int v,int d=0,ll now=0)//mnvZ
{
	//printf("%d %d %lld\n",v,d,now);
	seg.add(d,weight[v]);
	now+=weight[v];
	rt[d]=now;
	if(0<=v&&v<n)
	{
		int back=-1;
		if(d-K>=0) back=(int) (d-K);
		//printf("%d : %d %d\n",v,back,d);
		mn[v]=seg.get(back+1,d+1);
		sum[v]+=rt[d]-rt[d-zan[v]];
	}
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		dfs(to,d+1,now);
	}
}
void dfs1(int v,int d,ll gt,int L)
{
	ll z=K-d;
	//printf("* %d %lld\n",v,z);
	if(z>0)
	{
		sum[v]+=gt*(z/(ll) L);
		zan[v]=d+(z%L);
	}
	else zan[v]=K;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		dfs1(to,d+1,gt,L);
	}
}
int main()
{
	scanf("%d %lld",&n,&K);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&to[i]);
		deg[to[i]]++;
	}
	for(int i=0;i<n;i++) scanf("%lld",&weight[i]);
	for(int i=0;i<n;i++) mn[i]=INF;
	queue <int> que;
	for(int i=0;i<n;i++)
	{
		cycle[i]=true;
		if(deg[i]==0) que.push(i);
	}
	while(!que.empty())
	{
		int v=que.front();que.pop();
		cycle[v]=false;
		vec[to[v]].push_back(v);
		deg[to[v]]--;
		if(deg[to[v]]==0) que.push(to[v]);
	}
	seg.init(n*2+5);
	int sz=n;
	for(int i=0;i<n;i++)
	{
		if(cycle[i])
		{
			int now=i,t=0;
			ll all=0;
			do
			{
				nd[t++]=now;
				cycle[now]=false;
				all+=weight[now];
				now=to[now];
			}while(now!=i);
 			for(int j=0;j<t;j++) dfs1(nd[j],0,all,t);
			for(int j=t;j<2*t;j++)
			{
				weight[sz]=weight[nd[j-t]];
				nd[j]=sz++;
			}
			for(int j=0;j+1<2*t;j++)
			{
				int l=nd[j],r=nd[j+1];
				vec[r].push_back(l);
			}
			//for(int j=0;j<2*t;j++) printf("[%d %lld] ",nd[j],weight[nd[j]]);puts("");
			dfs(nd[2*t-1]);
		}
	}
	//for(int i=0;i<n;i++) printf("%lld\n",zan[i]);
	for(int i=0;i<n;i++) printf("%lld %lld\n",sum[i],mn[i]);
	return 0;
}