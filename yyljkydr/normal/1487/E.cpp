#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n[4],m[3],a[4][N],f[4][N];

vector<int>g[4][N];

int main()
{
	for(int i=0;i<4;i++)
		scanf("%d",&n[i]);
	for(int i=0;i<4;i++)
		for(int j=1;j<=n[i];j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<3;i++)
	{
		scanf("%d",&m[i]);
		for(int j=1;j<=m[i];j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			g[i+1][y].push_back(x);
		}
	}
	for(int i=1;i<=n[0];i++)
		f[0][i]=a[0][i];
	for(int i=1;i<4;i++)
		for(int j=1;j<=n[i];j++)
			f[i][j]=1e9;
	for(int i=1;i<4;i++)
	{
		multiset<int>ms;
		for(int j=1;j<=n[i-1];j++)
			ms.insert(f[i-1][j]);
		for(int j=1;j<=n[i];j++)
		{
			for(auto v:g[i][j])
				ms.erase(ms.find(f[i-1][v]));
			if(!ms.size())
			{
				for(auto v:g[i][j])
					ms.insert(f[i-1][v]);
				continue;
			}
			f[i][j]=*ms.begin()+a[i][j];
			for(auto v:g[i][j])
				ms.insert(f[i-1][v]);
		}
	}
	int ans=1e9;
	for(int i=1;i<=n[3];i++)
		ans=min(ans,f[3][i]);
	printf("%d\n",ans==1e9?-1:ans);
}