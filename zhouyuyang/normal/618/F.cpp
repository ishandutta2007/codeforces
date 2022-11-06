#include <cstdio>
#include <algorithm>

using namespace std;

long long g1[1200000],g2[1200000],h1[1200000],h2[1200000];
pair <int,int> p[1200000];
bool b[1200000];
int i,j,n,t;

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%I64d",&g1[i]);
	for (i=1;i<=n;i++)
		scanf("%I64d",&g2[i]);
	for (i=1;i<=n;i++)
		h1[i]=h1[i-1]+g1[i];
	for (i=1;i<=n;i++)
		h2[i]=h2[i-1]+g2[i];
	for (i=0;i<=n;i++)
	{
		t=upper_bound(h2+1,h2+n+1,h1[i])-h2-1;
		if (! b[h1[i]-h2[t]])
			p[h1[i]-h2[t]]=make_pair(i,t),b[h1[i]-h2[t]]=true;
		else
		{
			printf("%d\n",i-p[h1[i]-h2[t]].first);
			for (j=p[h1[i]-h2[t]].first+1;j<=i;j++)
				printf("%d ",j);
			printf("\n");
			printf("%d\n",t-p[h1[i]-h2[t]].second);
			for (j=p[h1[i]-h2[t]].second+1;j<=t;j++)
				printf("%d ",j);
			printf("\n");
			return 0;
		}
	}
}