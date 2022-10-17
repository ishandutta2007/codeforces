#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,k;

char s[N];

int ans[N],f[N];

unordered_map<int,int>vis;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		vis.clear();
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		if(k<=20)
		{
			for(int i=1;i<=n-k+1;i++)
			{
				int x=0;
				for(int j=1;j<=k;j++)
					x=x*2+((s[i+j-1]-'0')^1);
				vis[x]=1;
			}
			int w=-1;
			for(int i=0;i<1<<k;i++)
				if(vis.find(i)==vis.end())
				{
					w=i;
					break;
				}
			if(w==-1)
				puts("NO");
			else
			{
				puts("YES");
				for(int i=k-1;i>=0;i--)
					ans[k-i]=(w>>i)&1;
				for(int i=1;i<=k;i++)
					printf("%d",ans[i]);
				puts("");
			}
		}
		else
		{
			for(int i=1;i<=k-20;i++)
				ans[i]=0;
			f[n+1]=0;
			for(int i=n;i>=1;i--)
				if(s[i]=='0')
					f[i]=0;
				else
					f[i]=f[i+1]+1;
			for(int i=1;i<=n-k+1;i++)
			{
				int x=0;
				if(f[i]>=k-20)
				{
					for(int j=k-20+1;j<=k;j++)
						x=x*2+((s[i+j-1]-'0')^1);
					vis[x]=1;
				}
			}
			int w=-1;
			for(int i=0;i<1<<20;i++)
				if(vis.find(i)==vis.end())
				{
					w=i;
					break;
				}
			if(w==-1)
				puts("NO");
			else
			{
				puts("YES");
				for(int i=19;i>=0;i--)
					ans[k-i]=(w>>i)&1;
				for(int i=1;i<=k;i++)
					printf("%d",ans[i]);
				puts("");
			}
		}
	}
}