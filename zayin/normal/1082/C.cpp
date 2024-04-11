#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int m,n;
vector<int> a[maxn],sum[maxn];

bool cmq(int i,int j)
{
	return i>j;
}

void init()
{
	scanf("%d%d",&m,&n);
	while (m--)
	{
		int s,r;
		scanf("%d%d",&s,&r);
		a[s].push_back(r);	
	}
	for (int i=1;i<=n;++i)
	{
		sort(a[i].begin(),a[i].end(),cmq);
		
		sum[i].push_back(0);
		for (int j=0;j<a[i].size();++j)
			sum[i].push_back(a[i][j]+sum[i][j]);
	}
}

bool cmp(int i,int j)
{
	return a[i].size()<a[j].size();
}

int pos[maxn];

void solve()
{
	for (int i=1;i<=n;++i)
		pos[i]=i;
	sort(pos+1,pos+n+1,cmp);
	
	int ans=0,h=0;
	for (int k=1,j=1;k<=n;k=j)
	{
		while (j<=n&&a[pos[j]].size()==a[pos[k]].size())
			++j;
		
		for (;h<=a[pos[k]].size();++h)
		{
			int s=0;
			for (int i=k;i<=n;++i)
				s+=max(0,sum[pos[i]][h]);
			ans=max(ans,s);
		}
	}
	
	printf("%d\n",ans);
}

int main()
{
	init();
	solve();
	return 0;
}