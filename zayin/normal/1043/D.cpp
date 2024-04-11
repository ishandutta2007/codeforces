#include<bits/stdc++.h>
#define maxm 15
#define maxn 100050
using namespace std;
typedef long long LL;

int n,m;
int a[maxm][maxn];

int pos[maxm][maxn];

int ans[maxn];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i)
		for (int j=1;j<=n;++j)
		{
			scanf("%d",&a[i][j]);
			pos[i][a[i][j]]=j;
		}
	
	for (int k=n;k;--k)
	{
		int x=a[1][k];
		ans[x]=1;
//		cout<<"p:"<<x<<" "<<ans[x]<<endl;
		if (pos[1][x]==n)	continue;
		
		int y=a[1][pos[1][x]+1];
		
		bool flag=1;
		for (int i=1;flag&&i<=m;++i)
			if (pos[i][x]==n||a[i][pos[i][x]+1]!=y)
				flag=0;
		if (flag)
			ans[x]+=ans[y];
	}
	
	LL res=0;
	for (int i=1;i<=n;++i)
//		cout<<i<<" "<<ans[i]<<endl,
		res+=ans[i];
	cout<<res<<endl;
	return 0;
}