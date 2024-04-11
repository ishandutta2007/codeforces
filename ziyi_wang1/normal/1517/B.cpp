#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct path
{
	int w,x,y;
	friend bool operator < (path a,path b){return a.w<b.w;}
}p[10010];
int T,n,m,a[110][110],ans[110][110];
bool used[110][110];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				scanf("%d",&a[i][j]),p[(i-1)*m+j]=path{a[i][j],i,j};
		sort(p+1,p+1+n*m);
		for(int i=1;i<=m;++i)
		{
			ans[i][p[i].x]=a[p[i].x][p[i].y];
			used[p[i].x][p[i].y]=1;
		}
		for(int i=1;i<=n;++i)
			for(int j=1,t=1;j<=m;++j)
				if(!ans[j][i])
				{
					while(used[i][t])++t;
					ans[j][i]=a[i][t];++t;
				}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)printf("%d ",ans[j][i]);
			printf("\n");
		}
		for(int i=1;i<=n;++i)memset(used[i]+1,0,m);
		for(int i=1;i<=m;++i)memset(ans[i]+1,0,n<<2);
	}
	return 0;
}