#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],oc[N];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=n;i++)
			oc[a[i]]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ans=n+1;
		for(int i=1;i<=n;i++)
		{
			if(oc[a[i]])
				ans=min(ans,i-oc[a[i]]+1);
			oc[a[i]]=i;
		}
		if(ans!=n+1)
			printf("%d\n",ans) ;
		else
			puts("-1");
	}
}