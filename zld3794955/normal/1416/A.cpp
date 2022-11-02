#include<bits/stdc++.h>
using namespace std;
const int N=300030;
int n,ans[N]={};
vector<int> pos[N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			pos[i].clear();
			pos[i].push_back(0);
		}
		for(int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			pos[x].push_back(i);
		}
		for(int i=0;i<=n;++i)
			ans[i]=n+1;
		for(int i=n;i>=1;--i)
		{
			pos[i].push_back(n+1);
			int l=0;
			for(int j=1;j<(int)pos[i].size();++j)
				l=max(l,pos[i][j]-pos[i][j-1]);
			ans[l]=i;
		}
		for(int i=1;i<=n;++i)
		{
			ans[i]=min(ans[i],ans[i-1]);
			printf("%d ",ans[i]==n+1 ? -1 : ans[i]);
		}
		puts("");
	}
}