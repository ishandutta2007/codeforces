#include <cstdio>
#include <set>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
const int N=200001;
int n,m,K,r[N],cnt,du[N],Du[N],head[N],Cnt,Head[N],q[N],L[N],U[N],mk[N];
struct xint{int to,next;}e[N*2],E[N*2];
void addedge(int x,int y)
{
	e[++cnt]=(xint){y,head[x]};
	head[x]=cnt;du[y]++;
}
void Addedge(int x,int y)
{
	E[++Cnt]=(xint){y,Head[x]};
	Head[x]=Cnt;Du[y]++;
}
int h,t;
bool instk[N];
void dfs(int x)
{
	mk[x]=1;
	instk[x]=1;
	for(int i=head[x];i;i=e[i].next)
	{
		int y=e[i].to;
		if(instk[y])
		{
			cout<<-1<<endl;
			exit(0);
		}
		if(mk[y])continue;
		dfs(y);
	}
	instk[x]=0;
}
void check()
{
	memset(mk,0,sizeof mk);
	ref(i,1,n)if(!mk[i])dfs(i);
}
void work1()
{
	h=0,t=0;
	memset(mk,0,sizeof mk);
	memset(q,0,sizeof q);
	ref(i,1,n)L[i]=1;
	ref(i,1,n)if(r[i])q[++t]=i,L[i]=r[i],mk[i]=1;
	ref(i,1,n)if(!du[i]&&!r[i])q[++t]=i,L[i]=1,mk[i]=1;
	while(h++<t)
	{
		int u=q[h];
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(mk[v])continue;
			du[v]--;
			L[v]=max(L[v],L[u]+1);
			if(!du[v])q[++t]=v;
		}
	}
}
void work2()
{
	h=0,t=0;
	memset(mk,0,sizeof mk);
	memset(q,0,sizeof q);
	ref(i,1,n)U[i]=K;
	ref(i,1,n)if(r[i])q[++t]=i,U[i]=r[i],mk[i]=1;
	ref(i,1,n)if(!Du[i]&&!r[i])q[++t]=i,U[i]=K,mk[i]=1;
	while(h++<t)
	{
		int u=q[h];
		for(int i=Head[u];i;i=E[i].next)
		{
			int v=E[i].to;
			if(mk[v])continue;
			Du[v]--;
			U[v]=min(U[v],U[u]-1);
			if(!Du[v])q[++t]=v;
		}
	}
}
struct yint{int x,y,o;}sL[N],sU[N];
bool cmpx(yint a,yint b){return a.x<b.x;}
bool cmpy(yint a,yint b){return a.y<b.y;}
set<pair<int,int> > s;
int ans[N];
void work3()
{
	ref(i,1,n)if(L[i]>U[i])
	{
		cout<<-1<<endl;
		exit(0);
	}
	ref(i,1,n)sL[i].x=sU[i].x=L[i],sL[i].y=sU[i].y=U[i],sL[i].o=sU[i].o=i;
	sort(sL+1,sL+n+1,cmpx);
	sort(sU+1,sU+n+1,cmpy);
	int cnt1=1,cnt2=1;
	s.insert( make_pair(0,0) );
	s.insert( make_pair(2e9,2e9) );
	ref(i,1,K)
	{
		while(cnt1<=n&&sL[cnt1].x<=i) s.insert( make_pair(sL[cnt1].y,sL[cnt1].o) ), cnt1++;
		pair<int,int> S = *s.upper_bound( make_pair(0,0) );
		if(S.second>n)
		{
			cout<<-1<<endl;
			exit(0);
		}
		ans[S.second]=i; s.erase(S);
		while(cnt2<=n&&sU[cnt2].y<=i)
		{
			pair<int,int> S(sU[cnt2].y,sU[cnt2].o);
			if(!ans[sU[cnt2].o])
			{
				ans[sU[cnt2].o]=i;
				s.erase(S);
			}
			cnt2++;
		}
	}
	ref(i,1,n)printf("%d ",ans[i]);
	printf("\n");
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	ref(i,1,n)scanf("%d",&r[i]);
	ref(i,1,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(r[x]&&r[y]&&r[x]<=r[y])
		{
			cout<<-1<<endl;
			exit(0);
		}
		addedge(y,x);
		Addedge(x,y);
	}
	check();
	work1();
	work2();
	work3();
}