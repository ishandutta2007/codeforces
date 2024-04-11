#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,a[N],vis[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		fill(vis+1,vis+n+1,0);
		vector<int>ans;
		int now=n;
		for(int i=n,j;i>=1;i=j-1)
		{
			while(vis[now])
				now--;
			j=i;
			while(a[j]!=now)
				j--;
			for(int k=j;k<=i;k++)
				ans.push_back(a[k]),vis[a[k]]=1;
		}
		for(auto x:ans)
			printf("%d ",x);
		puts("");
	}
}