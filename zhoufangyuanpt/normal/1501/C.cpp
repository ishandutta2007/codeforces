#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int a[210000];
int p[2510000];
int cntx[5010000],cnty[5010000];
int g[210000],gy[210000];
vector<int> ggg[2510000];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ggg[a[i]].push_back(i);
		if(ggg[a[i]].size()==4)
		{
			puts("YES");
			printf("%d %d %d %d\n",ggg[a[i]][0],ggg[a[i]][1],ggg[a[i]][2],i);
			return 0;
		}
	}
	int x=0,q=0,gg=0;
	memset(p,0,sizeof(p));
	memset(cntx,0,sizeof(cntx));
	for(int i=1;i<=n;i++)
	{
		if(p[a[i]]!=0)
		{
			if(x!=0&&x!=a[i])
			{
				puts("YES");
				printf("%d %d %d %d\n",p[x],p[a[i]],q,i);
				return 0;
			}
			x=a[i];q=i;
			cntx[a[i]*2]=p[a[i]];cnty[a[i]*2]=i;
		}
		else
		{
			p[a[i]]=i,g[++gg]=a[i];
			gy[gg]=i;
		}
	}
	for(int i=1;i<=gg;i++)
	{
		for(int j=i+1;j<=gg;j++)
		{
			if(cntx[g[i]+g[j]]==0)cntx[g[i]+g[j]]=gy[i],cnty[g[i]+g[j]]=gy[j];
			else
			{
				puts("YES");
				printf("%d %d %d %d\n",cntx[g[i]+g[j]],cnty[g[i]+g[j]],gy[i],gy[j]);
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}