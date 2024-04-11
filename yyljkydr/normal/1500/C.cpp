#include<bits/stdc++.h>
using namespace std;

const int N=1501;

int n,m;

int a[N][N],b[N][N],r[N],vis[N];

vector<int>to[N];

set<int>s[N];

queue<int>q;

int py,viss[N];

bool cmp(int x,int y)
{
	return a[x][py]<a[y][py];
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	for(int i=1;i<=n;i++)
		r[i]=i;
	for(int j=1;j<=m;j++)
		for(int i=1;i<n;i++)
			if(b[i][j]>b[i+1][j])
				s[j].insert(i),to[i].push_back(j);
	for(int i=1;i<=m;i++)
		if(!s[i].size())
			q.push(i),viss[i]=1;
	vector<int>ans;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		ans.push_back(x);
		for(int j=1;j<n;j++)
			if(b[j][x]<b[j+1][x])
			{
				if(vis[j])
					continue;
				vis[j]=1;
				for(auto y:to[j])
				{
					s[y].erase(j);
					if(!s[y].size()&&!viss[y])
						q.push(y),viss[y]=1;
				}
			}
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans)
	{
		py=x;
		stable_sort(r+1,r+n+1,cmp);
	}
	int ok=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ok&=a[r[i]][j]==b[i][j];
	if(!ok)
		puts("-1");
	else
	{
		printf("%d\n",ans.size());
		for(auto x:ans)
			printf("%d ",x);
		puts("");
	}
}