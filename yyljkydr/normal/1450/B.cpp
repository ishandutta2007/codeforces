#include<bits/stdc++.h>
using namespace std;

const int N=101;

int T,n,x[N],y[N],k;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&x[i],&y[i]);
		int ans=-1;
		for(int i=1;i<=n;i++)
		{
			int ok=1;
			for(int j=1;j<=n;j++)
				ok&=(abs(x[i]-x[j])+abs(y[i]-y[j]))<=k;
			if(ok)
				ans=1;
		}
		printf("%d\n",ans);
	}
}