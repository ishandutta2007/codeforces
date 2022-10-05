#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
#define xxx 100100
#define yyy 100100
#define ll long long
using namespace std;
int a[xxx],n,m,c[xxx],st[xxx],en[xxx],dft=0,ans[xxx];
vector<int>r[xxx];
int bel[xxx],siz,tot;
struct que{
	int aa,bb,cc,p;
}q[xxx];

void dfs(int x,int fa)
{
	st[x]=++dft;
	a[dft]=c[x];
	for (int i=0;i<r[x].size();i++)
		if (r[x][i]!=fa)
			dfs(r[x][i],x);
	en[x]=dft;
}

bool cmp(que q1,que q2)
{
	return bel[q1.aa]!=bel[q2.aa]?bel[q1.aa]<bel[q2.aa]:q1.bb<q2.bb;
}

int sma=0,big=0;
int cnt[xxx],flbl[400],cc[xxx];

void add(int v)
{
	cc[v]++;
	cnt[cc[v]]++;
}

void del(int v)
{
	cnt[cc[v]]--;
	cc[v]--;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	int u,v,w;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		r[u].push_back(v);
		r[v].push_back(u);
	}
	dfs(1,0);
	
	siz=sqrt(n);
	for (int i=1;i<=n;i++)
		bel[i]=(i-1)/siz+1;
	tot=bel[n];
	
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		q[i].aa=st[u];
		q[i].bb=en[u];
		q[i].cc=v;
		q[i].p=i;
	}
	sort(q+1,q+m+1,cmp);
	
	for (int i=1;i<=m;i++)
	{
		if (!flbl[bel[q[i].aa]])
		{
			flbl[bel[q[i].aa]]=1;
			memset(cnt,0,sizeof(cnt));
			memset(cc,0,sizeof(cc));
			sma=big=q[i].aa;
			big--;
			while (big<q[i].bb)
			{
				add(a[big+1]);
				big++;
			}
		}
		else
		{
			if (sma>q[i].aa)
			{
				while (sma>q[i].aa)
				{
					add(a[sma-1]);
					sma--;
				}
			}
			
			if (big<q[i].bb)
			{
				while (big<q[i].bb)
				{
					add(a[big+1]);
					big++;
				}
			}
			
			if (big>q[i].bb)
			{
				while (big>q[i].bb)
				{
					del(a[big]);
					big--;
				}
			}
			
			if (sma<q[i].aa)
			{
				while (sma<q[i].aa)
				{
					del(a[sma]);
					sma++;
				}
			}
			
		}
		ans[q[i].p]=cnt[q[i].cc];
	}
	
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}