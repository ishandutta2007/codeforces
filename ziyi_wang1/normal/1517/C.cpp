#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p[510],ans[510][510];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)
	{
		int x=i,y=i,w=p[i];
		while(p[i]--)
		{
			ans[x][y]=w;
			if(y>1&&!ans[x][y-1])--y;
			else ++x;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}