#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
int a[100010];
ll f[100010];
typedef pair<int,int> pii;
pii c[20][1000010];
pii query(int l,int r)
{
	int x=0;
	while(1<<(x+1)<=r-l+1)
		x++;
	return max(c[x][l],c[x][r-(1<<x)+1]);
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[0][i]=pii(a[i],i);
	}
	c[0][n]=pii(n,n);
	for(i=1;i<=19;i++)
		for(j=1;j+(1<<i)-1<=n;j++)
			c[i][j]=max(c[i-1][j],c[i-1][j+(1<<(i-1))]);
	f[n]=0;
	ll ans=0;
	for(i=n-1;i>=1;i--)
	{
		pii v=query(i+1,a[i]);
		f[i]=f[v.second]+n-i+v.second-a[i];
		ans+=f[i];
	}
	printf("%I64d\n",ans);
	return 0;
}