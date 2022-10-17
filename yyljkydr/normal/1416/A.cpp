#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T;

int n,a[N];

int ans[N];

vector<int>v[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			v[i].clear(),v[i].push_back(0);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),v[a[i]].push_back(i);
		for(int i=1;i<=n;i++)
			v[i].push_back(n+1);
		for(int i=1;i<=n;i++)
			ans[i]=n+1;
		for(int i=1;i<=n;i++)
		{
			int mx=0;
			for(int j=0;j+1<v[i].size();j++)
				mx=max(mx,v[i][j+1]-v[i][j]);
			ans[mx]=min(ans[mx],i);
		}
		int out=n+1;
		for(int i=1;i<=n;i++)
		{
			out=min(out,ans[i]);
			printf("%d%c",out==n+1?-1:out," \n"[i==n]);
		}
	}
}