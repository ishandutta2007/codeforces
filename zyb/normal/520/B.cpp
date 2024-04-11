#include<stdio.h>
using namespace std;
struct node
{
	int x,t;
}q[100005];
int i,j,k,l,s,m,n,vis[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	int gt=m-n;
	int l=0,r=1;
	q[1].x=n;
	q[1].t=0;
	vis[n]=1;
	while (l<r)
	{
		int k=q[++l].x;
		if (k==m)
		{
			printf("%d\n",q[l].t);
			return 0;
		}
		if (k<m)
		{
			if (!vis[k*2])
			{
				q[++r].x=k*2,vis[k*2]=1;
				
				q[r].t=q[l].t+1;
			}
			if (!vis[k-1]&&k-1>0)
			{
				q[++r].x=k-1;
				q[r].t=q[l].t+1;
				vis[k-1]=1;
			}
		}
		else
		{
			if (!vis[k-1])
			{
				q[++r].x=k-1;q[r].t=q[l].t+1;
				vis[k-1]=1;
			}
		}
	}
}