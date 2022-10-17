#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N],cnt[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<=30;i++)
			cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			for(int j=0;j<31;j++)
				if(a[i]&(1<<j))
					cnt[j]++;
		}
		int ans=-1;
		for(int i=30;i>=0;i--)
			if(cnt[i]&1)
			{
				int b1=cnt[i]/2,a1=cnt[i]-b1;
				int c0=n-cnt[i];
				if((a1&1)==(b1&1))
					continue;
				if(a1&1)
					ans=1;
				else
					ans=0;
				if((c0&1)&&ans==0)
					ans=1;
				break;
			}
		if(ans==-1)
			puts("DRAW");
		else if(ans==1)
			puts("WIN");
		else if(ans==0)
			puts("LOSE");
	}
}