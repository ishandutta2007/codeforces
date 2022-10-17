#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],b[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			a[i]=b[i]-a[i];
		int mn=n,mx=0,tmp=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=0)
			{
				tmp=a[i];
				mn=min(mn,i);
				mx=max(mx,i);
			}
		if(mn==n&&mx==1&&tmp==0)
		{
			puts("Yes");
			continue;
		}
		bool ans=true;
		if(tmp<0)
			ans=false;
		for(int i=1;i<mn;i++)
			if(a[i]!=0)
				ans=false;
		for(int i=mx+1;i<=n;i++)
			if(a[i]!=0)
				ans=false;
		for(int i=mn;i<=mx;i++)
			if(a[i]!=tmp)
				ans=false;
		puts(ans?"Yes":"No");
	}
}