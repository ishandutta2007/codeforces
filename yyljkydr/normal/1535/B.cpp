#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int T;

int n,a[N];

int c[2];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		c[0]=c[1]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),c[a[i]&1]++;
		int ans=c[0]*c[1]+c[0]*(c[0]-1)/2;
		for(int i=1;i<=n;i++)
			if(a[i]&1)
				for(int j=i+1;j<=n;j++)
					if(a[j]&1)
						ans+=__gcd(a[i],a[j])>1;
		printf("%d\n",ans);
	}
}