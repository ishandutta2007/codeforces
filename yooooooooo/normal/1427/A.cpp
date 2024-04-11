#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,tot[2],a[2][55],b,x,sum[2],pt;
bool cmp(int a,int b){return abs(a)>abs(b);}
void prt(int rt)
{
	for(int i=1;i<=tot[rt];i++)printf("%d ",a[rt][i]);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		tot[0]=tot[1]=0;
		sum[0]=sum[1]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x>=0)a[0][++tot[0]]=x,sum[0]+=x;
			else a[1][++tot[1]]=x,sum[1]-=x;
		}
		sort(a[0]+1,a[0]+tot[0]+1,cmp);
		sort(a[1]+1,a[1]+tot[1]+1,cmp);
		if(sum[0]==sum[1])printf("NO\n");
		else
		{
			pt=0;
			if(sum[1]>sum[0])pt=1;
			printf("YES\n");
			prt(pt);
			prt(1-pt);
			printf("\n");
		}
	}
	return 0;
}