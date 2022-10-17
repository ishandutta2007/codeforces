#include<bits/stdc++.h>
using namespace std;

const int N=3e3+1e2+7;

int T,n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s+=a[i];
		int ans=n;
		for(int i=1;i<=n;i++)
			if(s%i==0)
			{
				bool ok=1;
				int t=0;
				for(int j=1;j<=n;j++)
				{
					t+=a[j];
					if(t>s/i)
						ok=0;
					else if(t==s/i)
						t=0;
				}
				if(t!=0)
					ok=0;
				if(ok)
					ans=min(ans,n-i);
			}
		printf("%d\n",ans);
	}	
}