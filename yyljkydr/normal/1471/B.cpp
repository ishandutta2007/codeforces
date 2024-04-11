#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,x;

int a[N*31];

long long b[N*31];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		long long ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),b[i]=1;
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%x==0&&flag==1)
				a[++n]=a[i]/x,b[n]=x*b[i];
			else
				flag=0;
			ans+=1ll*a[i]*b[i];
		}
		printf("%lld\n",ans);
	}
}