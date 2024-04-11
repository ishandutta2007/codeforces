#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm> 
#define maxn 205000
using namespace std;

int sz=0;
struct node
{
	int u,v;
	node(int u=0,int v=0)	:u(u),v(v)	{
	}
}	E[maxn];

int n;

int cnt[maxn];

int vis[maxn];

int init()
{
	scanf("%d",&n);
	for (int k=1;k<n;++k)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if (u!=n&&v!=n)
			return 0; 
		++cnt[u+v-n];
		vis[u+v-n]=2;
	}
	return 1;
}

void solve()
{
	int k=n;
	for (int i=n-1,j=n-1;i;--i)
	{
		if (vis[i]!=2)	continue;
		vis[i]=1;
		// cout<<i<<":"<<endl;
		while (--cnt[i])
		{
			while (j&&vis[j])	--j;
			if (!j||j>i)
			{
				printf("NO\n");
				return;
			}
			vis[j]=1;
			// cout<<cnt[i]<<" "<<j<<endl;
			E[sz++]=node(j,k);
			k=j;
		}
		E[sz++]=node(i,k);
		k=i;
		
		// printf("%d %d\n",i,j); 
	}
	
	if (sz!=n-1)
	{
		printf("NO\n");
		return;
	} else
	{
		printf("YES\n");
		for (int i=0;i<sz;++i)
			printf("%d %d\n",E[i].u,E[i].v);
	}
}

int main()
{
	// freopen("c.in","r",stdin);
	if (init())
		solve(); 
	else
		printf("NO\n");
	return 0;
}