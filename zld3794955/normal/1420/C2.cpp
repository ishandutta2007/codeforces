#include<bits/stdc++.h>
using namespace std;
const int N=300030;
int T,n,q,a[N]={},x,y;
long long ans=0;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		a[0]=0;
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		a[n+1]=0;
		ans=0;
		for(int i=2;i<=n+1;++i)
			ans=ans+max(0,a[i-1]-a[i]);
		printf("%I64d\n",ans);
		for(int i=1;i<=q;++i)
		{
			scanf("%d%d",&x,&y);
			if(x>y)
				swap(x,y);
			if(x+1==y)
			{
				ans=ans-max(0,a[x-1]-a[x])-max(0,a[x]-a[y])-max(0,a[y]-a[y+1]);
				swap(a[x],a[y]);
				ans=ans+max(0,a[x-1]-a[x])+max(0,a[x]-a[y])+max(0,a[y]-a[y+1]);
			}
			else
			{
				ans=ans-max(0,a[x-1]-a[x])-max(0,a[x]-a[x+1]);
				ans=ans-max(0,a[y-1]-a[y])-max(0,a[y]-a[y+1]);
				swap(a[x],a[y]);
				ans=ans+max(0,a[x-1]-a[x])+max(0,a[x]-a[x+1]);
				ans=ans+max(0,a[y-1]-a[y])+max(0,a[y]-a[y+1]);
			}
			printf("%I64d\n",ans);
		}
	}
}