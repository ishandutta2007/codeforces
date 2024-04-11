#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxc 30
#define maxn 100500
using namespace std;

int n;
char s[maxn],t[maxn];

int map[maxc][maxc];

bool link[maxc][maxc];

bool vis[maxc];

int ans;

void join(int i,int j)
{
	map[i][j]=map[j][i]=1;
}

void init()
{
	scanf("%d",&n);
	scanf("%s%s",s,t);
	
	for (int i=0;i<n;++i)
		join(s[i]-'a',t[i]-'a');
}

void dfs(int i)
{
	vis[i]=1;
	for (int j=0;j<maxc;++j)
		if (map[i][j]&&!vis[j])
			++ans,link[i][j]=link[j][i]=1,dfs(j);
}

void solve()
{
	memset(vis,0,sizeof(vis));
	memset(link,0,sizeof(link));
	
	for (int i=0;i<maxc;++i)
		if (!vis[i])
			dfs(i);
			
	cout<<ans<<endl;
	for (int i=0;i<maxc;++i)
		for (int j=i;j<maxc;++j)
			if (link[i][j])
				printf("%c %c\n",i+'a',j+'a');
}

int main()
{
//	freopen("c.in","r",stdin);
	init();
	solve();
	return 0;
}