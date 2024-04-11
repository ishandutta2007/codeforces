#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 1001000
using namespace std;

int n,m,first[N],ds[N],bb,bj[N];
bool ok[N];
struct Bn
{
	int to,next;
} bn[N<<1];
vector<int>ans;

inline void add(int u,int v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

int main()
{
	memset(first,-1,sizeof(first));
	int i,j,o,p,q,t;
	cin>>n>>m;
	for(i=1; i<=m; i++)
	{
		scanf("%d%d",&p,&q);
		add(p,q);
	}
	for(i=1; i<=n; i++)
	{
		if(bj[i]) continue;
		bj[i]=1;
		for(p=first[i];p!=-1;p=bn[p].next)
		{
			if(!bj[bn[p].to])
			{
				bj[bn[p].to]=-1;
			}
		}
	}
	for(i=n;i>=1;i--)
	{
		if(bj[i]!=1 || ok[i]) continue;
		ans.push_back(i);
		for(p=first[i];p!=-1;p=bn[p].next)
		{
			bj[bn[p].to]=-1;
		}
	}
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
}