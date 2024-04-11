#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int n,a[N],b[N],vis[N],g[N*2];

int cho[N],sp[N],pos[N];

int main()
{
	scanf("%d",&n);
	if(n%2==0)
	{
		puts("First");
		fflush(stdout);
		for(int i=1;i<=n;i++)
			printf("%d ",i);
		for(int i=1;i<=n;i++)
			printf("%d ",i);
		puts("");
		fflush(stdout);
	}
	else
	{
		puts("Second");
		fflush(stdout);
		for(int i=1;i<=n*2;i++)
		{
			int x;
			scanf("%d",&x);
			sp[i%n]+=x;
			g[i]=x;
			if(!a[x])
				a[x]=i;
			else
				b[x]=i;
		}
		long long sum=0;
		vector<int>ans;
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				int x=i;
				int t=a[x]%n;
				while(!vis[x])
				{
					vis[x]=1;
					if(a[x]%n==t)
						cho[x]=0,sum+=a[x],t=b[x],ans.push_back(a[x]);
					else
						cho[x]=1,sum+=b[x],t=a[x],ans.push_back(b[x]);
					t%=n;
					x=sp[t]-x;
				}
			}
		if(sum&1)
		{
			ans.clear();
			for(int i=1;i<=n;i++)
				if(cho[i]==0)
					ans.push_back(b[i]);
				else
					ans.push_back(a[i]);
		}
		for(auto x:ans)
			printf("%d ",x);
		puts("");
		fflush(stdout);
	}
}