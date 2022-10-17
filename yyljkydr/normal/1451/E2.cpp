#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,q[N],vis[N],a[N];

int query(int x,int y)
{
	printf("XOR %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}

int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		q[i]=query(1,i);
	for(int i=2;i<=n;i++)
	{
		if(q[i]==0)//1  i
		{
			printf("AND %d %d\n",1,i);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			a[1]=a[i]=x;
			for(int j=2;j<=n;j++)
				if(j!=i)
					a[j]=q[j]^a[1];
			printf("! ");
			for(int i=1;i<=n;i++)
				printf("%d%c",a[i]," \n"[i==n]);
			return 0;
		}
		else if(vis[q[i]])//vis[q[i]]  i
		{
			printf("AND %d %d\n",vis[q[i]],i);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			a[vis[q[i]]]=a[i]=x;
			a[1]=x^q[i];
			for(int j=2;j<=n;j++)
				if(j!=i&&j!=vis[q[i]])
					a[j]=q[j]^a[1];
			printf("! ");
			for(int i=1;i<=n;i++)
				printf("%d%c",a[i]," \n"[i==n]);
			return 0;
		}
		vis[q[i]]=i;
	}
	int x=-1,y=-1;
	for(int i=2;i<=n;i++)
		if(q[i]==1)
			x=i;
		else if(q[i]==2)
			y=i;
	assert(x!=-1);
	assert(y!=-1);
	int u,v;
	printf("AND 1 %d\n",x);
	fflush(stdout);
	scanf("%d",&u);
	printf("AND 1 %d\n",y);
	fflush(stdout);
	scanf("%d",&v);
	a[1]=u-(u&1)+(v&1);
	for(int i=2;i<=n;i++)
		a[i]=a[1]^q[i];
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d%c",a[i]," \n"[i==n]);
}