#include<stdio.h>
#include<algorithm>
using namespace std;
int i,j,k,l,s,m,n,ans;
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%d%d",&j,&l);
	if (l<=k)
	ans=j;
	else
	ans=j-(l-k);
	for (i=2;i<=n;i++)
	{
		scanf("%d%d",&j,&l);
		if (l<=k)
		ans=max(ans,j);
		else
		ans=max(ans,j-(l-k));
	}
	printf("%d\n",ans);
}