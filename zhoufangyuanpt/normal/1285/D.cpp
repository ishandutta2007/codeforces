//luogu
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[110000];
int dfs(int l,int r,int dep)
{
	if(dep<0)return 0;
	int i;
	for(i=l;i<=r;i++)
	{
		if(a[i]&1<<dep)break;
	}
	if(dep>0&&l<i&&i<=r)
	{
		int ls=dfs(l,i-1,dep-1),rs=dfs(i,r,dep-1);
		if(ls>rs)ls=rs;
		return (1<<dep)+ls;
	}
	else
	{
		if(i==l)return dfs(l,r,dep-1);
		else if(i==r+1)return dfs(l,r,dep-1);
		else return 1;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	printf("%d\n",dfs(1,n,29));
	return 0;
}