#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
double f[1010][1010];
int vis[1010][1010];
double dfs(int x,int y)
{
	if(x<0||y<0)
		return 0;
	if(!x)
		return 0;
	if(!y)
		return 1;
	if(vis[x][y])
		return f[x][y];
	double ans=0;
	ans+=1.*x/(x+y);
	if(y>=2)
		ans+=dfs(x-1,y-2)*y/(x+y)*(y-1)/(x+y-1)*x/(x+y-2);
	if(y>=3)
		ans+=dfs(x,y-3)*y/(x+y)*(y-1)/(x+y-1)*(y-2)/(x+y-2);
	vis[x][y]=1;
	f[x][y]=ans;
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(vis,0,sizeof vis);
	printf("%.10lf\n",dfs(n,m));
	return 0;
}