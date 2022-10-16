#include<cstdio>
#include<vector>

using namespace std;

int cp[2000];bool E[2000][2000],vis[2000];
int s,b,small[2000],big[2000];

int fnd(int j)
{
	for(int i=1;i<=s;i++)
	{
		if(!vis[i]&&E[i][j])
		{
			vis[i]=1;
			if(!cp[i]||fnd(cp[i])){cp[i]=j;return 1;}
		}
	}
	return 0;
}

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);
	for(int i=1,t=0;i<=n;i++)
	{
		scanf("%d",&t);if(2*t>=m){puts("-1");return 0;}
		if(3*t<=m)small[++s]=t;else big[++b]=t;
	}
	for(int i=1;i<=s;i++)for(int j=1;j<=b;j++)if(big[j]%small[i]==0&&2*big[j]+small[i]<=m)E[i][j]=1;
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=s;j++)vis[j]=0;
		if(!fnd(i)){puts("-1");return 0;}
	}
	vector<pair<int,int> > ans;
	for(int i=1;i<=s;i++)
	{
		if(cp[i])
		{
			ans.push_back(make_pair(big[cp[i]]+small[i],2*big[cp[i]]+small[i]));
		}
		else{ans.push_back(make_pair(2*small[i],3*small[i]));}
	}
	printf("%d\n",ans.size());for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].first,ans[i].second);
}