#include<bits/stdc++.h>
using namespace std;
const int N=500500;
int n,a[N]={},ans=0;
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	a[n+1]=a[n];
	for(int i=2,l=1;i<=n+1;++i)
	{
		if(a[i]==a[i-1])
		{
			ans=max(ans,(i-l-1)/2);
			if(a[i]==a[l])
				for(int j=l;j<=i;++j)
					a[j]=a[l];
			else
			{
				int t=(i-l-2)/2;
				for(int j=l;j<=l+t;++j)
					a[j]=a[l];
				for(int j=l+t+1;j<=i;++j)
					a[j]=a[i];
			}
			l=i;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}