#include<cstdio>
#include<algorithm>
using namespace std;
int T;
int n,m,sum=0,x,y,a[305][305],mov[4][2]={0,1,0,-1,1,0,-1,0},u,v,ok;
int leg(int x,int y)
{
	return x&&y&&x<=n&&y<=m;
}
int main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);ok=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&x);
				sum=0;
				for(int k=0;k<4;k++)
				{
					u=i+mov[k][0];
					v=j+mov[k][1];
					if(leg(u,v))sum++;
				}
				if(x>sum)ok=1;
				a[i][j]=sum;
			}
		}
		if(ok)printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)printf("%d ",a[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}