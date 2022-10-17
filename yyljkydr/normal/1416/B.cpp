#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

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
		if(s%n)
		{
			puts("-1");
			continue;
		}
		printf("%d\n",3*(n-1));
		for(int i=2;i<=n;i++)
		{
			int w=(i-a[i]%i)%i;
			printf("%d %d %d\n",1,i,w);
			a[1]-=w;
			a[i]+=w;
			w=a[i]/i;
			printf("%d %d %d\n",i,1,w);
			a[1]+=a[i];
			a[i]=0;
		}
		for(int i=2;i<=n;i++)
			printf("%d %d %d\n",1,i,a[1]/n);
	}
}