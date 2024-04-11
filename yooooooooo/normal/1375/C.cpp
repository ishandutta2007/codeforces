#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,a[300005],u,v;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);u=n+1;v=n+1;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		if(a[1]<=(n+1)/2)u=min(a[1],u);
		else v=min(v,n-a[1]+1);
		if(a[n]>(n+1)/2)u=min(n-a[n]+1,u);
		else v=min(a[n],v);
		if(u<v)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}