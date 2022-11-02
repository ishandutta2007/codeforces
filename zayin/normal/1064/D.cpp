#include<bits/stdc++.h>
#define maxn 2050
#define maxp (maxn*maxn)
using namespace std;

int n,m,x,y,L,R;

char mp[maxn][maxn];

int N,col[maxp],cnt[maxp];

vector<int> G[maxp];

int belong[maxn][maxn];

void init()
{
	scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&L,&R);
	for (int i=0;i<n;++i)
		scanf("%s",mp[i]);
}

void join(int u,int v)
{
//	cout<<u<<" <-> "<<v<<endl;
	G[u].push_back(v);
	G[v].push_back(u);
}

void build()
{
	for (int j=0;j<m;++j)
		for (int i=0;i<n;++i)
		{
			if (mp[i][j]=='*')	continue;
			if (!i||mp[i-1][j]=='*')	
				col[++N]=j;
			++cnt[N];
			belong[i][j]=N;
		}
	
	/*for (int i=0;i<n;++i)
	{
		for (int j=0;j<m;++j)
			cout<<belong[i][j]<<" ";
		cout<<endl;
	}*/
	
	for (int i=0;i<n;++i)
		for (int j=1;j<m;++j)
			if (belong[i][j]&&belong[i][j-1])
				join(belong[i][j],belong[i][j-1]);
}

int dis[maxp];
queue<int> q;

bool judge(int i)
{
	int j=col[i],l,r;
	if (j<=y)
		l=(dis[i]+(y-j))>>1,r=(dis[i]-(y-j))>>1;
	else
		l=(dis[i]-(j-y))>>1,r=(dis[i]+(j-y))>>1;
//	cout<<i<<" "<<dis[i]<<" "<<l<<" "<<r<<endl;
	return l<=L&&r<=R;
}

void solve()
{
	build();
	memset(dis,-1,sizeof(dis));
	
	int s=belong[--x][--y];
	q.push(s);
	dis[s]=0;
	while (!q.empty())
	{
		int i=q.front();	q.pop();
//		cout<<"dis["<<i<<"]="<<dis[i]<<endl;
		for (auto j:G[i])
		{
			if (~dis[j])	continue;
			q.push(j);
			dis[j]=dis[i]+1;
		}
	}
	
	int ans=0;
	for (int i=1;i<=N;++i)
		if (~dis[i]&&judge(i))
//			cout<<"ok:"<<i<<endl,
			ans+=cnt[i]; 
	cout<<ans<<endl;
}

int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	init();
	solve();
	return 0;
}