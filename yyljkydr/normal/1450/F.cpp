#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int a[N],c[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		fill(c+1,c+n+1,0);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),c[a[i]]++;
		int ans=0;
		for(int i=1;i<=n;i++)
			if(c[i]>(n+1)/2)
				ans=-1;
		if(ans==-1)
			puts("-1");
		else
		{
			fill(c+1,c+n+1,0);
			int last=1,s=0;
			for(int i=2;i<=n;i++)
				if(a[i]==a[i-1])
				{
					c[a[last]]++;
					c[a[i-1]]++;
					s+=2;
					ans++;
					last=i;
				}
			c[a[last]]++;
			c[a[n]]++;
			s+=2;
			int pmx=0;
			for(int i=1;i<=n;i++)
				if(c[i]>c[pmx])
					pmx=i;
			c[pmx]--,s--;
			pmx=0;
			for(int i=1;i<=n;i++)
				if(c[i]>c[pmx])
					pmx=i;
			c[pmx]--,s--;
			pmx=0;
			for(int i=1;i<=n;i++)
				if(c[i]>c[pmx])
					pmx=i;
			if(c[pmx]<=s/2)
				printf("%d\n",ans);
			else
				printf("%d\n",ans+c[pmx]-s/2);
		}
	}
}