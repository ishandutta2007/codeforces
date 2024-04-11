#include<stdio.h>
using namespace std;
bool b[100005];
int i,j,k,l,m,n,s,s1;
inline int max(int o,int p)
{
	if (o>p)
	return o;
	else return p;
}
int main()
{
	scanf("%d%d",&n,&m);
	s=n-1;
	for (i=1;i<=m;i++)
	{
		scanf("%d",&j);
		if (j==1)
		{
			scanf("%d%d",&k,&l);
			b[k]=b[l]=true;
			s-=2;
		}
		else
		{
			scanf("%d",&k);
			b[k]=true;
			s--;
		}
	}
	int ans=0;
	for (i=1;i<n-1;i++)
	if (!b[i]&&!b[i+1])
	{
		b[i]=b[i+1]=true;
		ans++;
	}
	printf("%d %d\n",s-ans,s);
}