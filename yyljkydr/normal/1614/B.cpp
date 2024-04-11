#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n;

int a[N],r[N],pos[N];

bool cmp(int x,int y)
{
	return a[x]>a[y];
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),r[i]=i;
		sort(r+1,r+n+1,cmp);
		long long ans=0;
		int L=-1,R=1;
		for(int i=1;i<=n;i++)
		{
			int x=r[i];
			if(L==-R)
			{
				ans+=1ll*R*a[x];
				pos[x]=R;
				R++;
			}
			else
			{
				ans+=1ll*(-L)*a[x];
				pos[x]=L;
				L--;
			}
		}
		printf("%lld\n",ans*2);
		for(int i=0;i<=n;i++)
			printf("%d ",pos[i]);
		puts("");
	}	
}